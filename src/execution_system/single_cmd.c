/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/30 05:44:13 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_single_command(t_env *env, t_lst *temp)
{
	int		access;
	int		exec;
	char	*new;

	free_cmd(env);
	replace_spaces(temp->token->cmd);
	new = remove_quotes(temp->token->cmd);
	access = verify_command(new, env->paths, env);
	if (access == 0)
	{
		if (new != NULL)
			free(new);
		join_cmd_arg(temp, env);
		exec = cmd_execve(env, env->input, env->output);
		define_exec_error(exec);
	}
	else
	{
		exec_error(new, env);
		if (new != NULL)
			free(new);
	}
}

int	cmd_execve(t_env *env, int input, int output)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	execve_signal();
	if (pid == 0)
	{
		dup2(input, STDIN_FILENO);
		dup2(output, STDOUT_FILENO);
		if (execve(env->cmd, env->cmd_exec, env->envp) == -1)
		{
			perror("minishell");
			free_here_docs(0);
		}
		if (input != STDIN_FILENO)
			close(input);
		if (output != STDOUT_FILENO)
			close(output);
	}
	else if (pid == -1)
		ft_putendl_fd("\nFailed forking child..", STDERR_FILENO);
	wait(&status);
	reset_io(&input, &output);
	return (status);
}

void	join_cmd_arg(t_lst *temp, t_env *env)
{
	int		count;
	int		size;
	char	**elem;

	elem = NULL;
	count = 1;
	size = 0;
	if (temp->token->option != NULL)
		count++;
	if (temp->token->arg != NULL)
	{
		elem = ft_split(temp->token->arg, ' ');
		size = get_size(elem);
	}
	count += size;
	if (env->cmd_exec != NULL)
		free_temp(env->cmd_exec);
	env->cmd_exec = (char **)ft_calloc(count + 1, sizeof(char *));
	transfer_cmd(count, temp, env, elem);
	if (elem != NULL)
		free_temp(elem);
}

int	transfer_first(t_lst *temp, t_env *env, char **elem, int x)
{
	char	*new;

	if (temp->token->option != NULL)
	{
		replace_spaces(temp->token->option);
		new = remove_quotes(temp->token->option);
		env->cmd_exec[1] = ft_strdup(new);
		free(new);
	}
	else
	{
		if (temp->token->arg != NULL)
		{
			replace_spaces(elem[x]);
			new = remove_quotes(elem[x]);
			env->cmd_exec[1] = ft_strdup(new);
			free(new);
			x++;
		}
	}
	return (x);
}

void	transfer_cmd(int count, t_lst *temp, t_env *env, char **elem)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < count)
	{
		if (i == 0)
			first_cmd_ready(temp, env);
		else if (i == 1)
			x = transfer_first(temp, env, elem, x);
		else
		{
			if (temp->token->arg != NULL)
			{
				if (elem[x] != NULL)
				{
					cmd_ready_execution(env, elem[x], i);
					x++;
				}
			}
		}
		i++;
	}
}
