/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:49:47 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 20:06:30 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	find_path(t_env *env)
{
	char	*string;

	string = get_env(&(*env->stack), "PATH");
	if (string != NULL)
		env->cmd_envp = ft_strdup(string);
	else
		env->cmd_envp = ft_strdup("");
	env->paths = ft_split(env->cmd_envp, ':');
}

int	verify_command(char *cmd, char **paths, t_env *env)
{
	char	*new_cmd;
	int		ok;
	int		flag;

	flag = 0;
	if ((ft_strncmp(cmd, "/usr/bin/", 9) == 0) || \
	((ft_strncmp(cmd, "/bin/", 5) == 0)))
	{
		new_cmd = ft_strrchr(cmd, '/');
		cmd = ft_strdup(new_cmd + 1);
		flag++;
	}
	ok = confirm_command(env, cmd, paths);
	if (flag > 0)
		free(cmd);
	if (ok == 0)
		return (0);
	return (1);
}

int	confirm_command(t_env *env, char *cmd, char **paths)
{
	char	*command;
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
		{
			env->cmd = ft_strdup(command);
			free(command);
			return (0);
		}
		free(command);
		paths++;
	}
	return (1);
}

void	cmd_ready_execution(t_env *env, char *string, int i)
{
	char	*new;

	replace_spaces(string);
	new = remove_quotes(string);
	env->cmd_exec[i] = ft_strdup(new);
	free(new);
}

void	first_cmd_ready(t_lst *temp, t_env *env)
{
	char	*new;

	replace_spaces(temp->token->cmd);
	new = remove_quotes(temp->token->cmd);
	env->cmd_exec[0] = ft_strdup(new);
	free(new);
}
