/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:32:55 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/30 10:51:49 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	verify_execute(t_lst *temp, t_env *env)
{
	env->size = 0;
	env->pipe_count = 0;
	set_standard_io(&env->input, &env->output);
	pipeline_check(temp, env);
	free_cmd_path(env);
	find_path(env);
	while (temp != NULL)
	{
		env->size++;
		if (temp->token->type == 6)
			handle_builtin(temp, env, temp->token->arg, temp->token->type);
		else if (temp->token->type == 2)
			handle_cmd(temp, env, temp->token->arg, temp->token->type);
		else if (temp->token->type == 5)
			redirection_handle(temp->token->redir, env, \
			temp->token->type, temp);
		else
			if (env->output != STDOUT_FILENO)
				close(env->output);
		temp = temp->next;
	}
}

void	handle_builtin(t_lst *temp, t_env *env, char *arg, int type)
{
	char	*new;

	verify_redirection_io(arg, env, type);
	replace_spaces(temp->token->cmd);
	new = remove_quotes(temp->token->cmd);
	execute_single_builtin(temp, env, new);
	if (new != NULL)
		free(new);
	reset_io(&env->input, &env->output);
}

void	handle_cmd(t_lst *temp, t_env *env, char *arg, int type)
{
	verify_redirection_io(arg, env, type);
	execute_single_command(env, temp);
	reset_io(&env->input, &env->output);
}

void	redirection_handle(char *redir, t_env *env, int type, t_lst *temp)
{
	int		result;
	char	*new;

	verify_redirection_io(redir, env, type);
	if (env->input == -2 || env->output == -2)
		return ;
	if (temp->token->cmd != NULL)
	{
		replace_spaces(temp->token->cmd);
		new = remove_quotes(temp->token->cmd);
		result = execute_single_builtin(temp, env, new);
		if (new != NULL)
			free(new);
		if (result == 1)
			execute_single_command(env, temp);
	}
	else
		reset_io(&env->input, &env->output);
}
