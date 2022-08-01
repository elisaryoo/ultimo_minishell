/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:02:13 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:51:55 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pipeline_check(t_lst *temp, t_env *env)
{
	env->pipe_count = 0;
	while (temp != NULL)
	{
		env->pipe_count++;
		temp = temp->next;
	}
}

void	free_cmd_path(t_env *env)
{
	if (env->cmd_envp != NULL)
		free(env->cmd_envp);
	if (env->paths != NULL)
		free_temp(env->paths);
}

void	check_redir_type(t_env *env, char *redir, int *io)
{
	char	**elem;

	env->flag_in = 0;
	env->flag_out = 0;
	elem = ft_split(redir, ' ');
	count_io(env, elem);
	if (env->flag_out != 0)
	{
		if (*io != STDOUT_FILENO)
			close(*io);
		env->output = output_redir(elem);
	}
	if (env->flag_in != 0)
	{
		if (env->input != STDIN_FILENO)
			close(env->input);
		env->input = input_redir(elem, env);
	}
	free_temp(elem);
}

void	free_cmd(t_env *env)
{
	if (env->cmd != NULL)
	{
		free(env->cmd);
		env->cmd = NULL;
	}
}
