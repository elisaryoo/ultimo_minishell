/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:18:03 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/30 10:18:43 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_valid_error(char **elem, char *new)
{
	ft_putendl_fd("minishell: exit: numeric argument required", \
	STDERR_FILENO);
	free_temp(elem);
	if (new != NULL)
		free(new);
	g_error_code = 2;
}

void	free_exit(t_lst *temp, t_env *env, char **args)
{
	free_temp(env->paths);
	free_temp(env->cmds);
	free(env->string);
	free_stack(&(env->stack));
	free_token_lst(&(temp));
	free_prompt(env);
	if (env->user != NULL)
		free(env->user);
	if (env->home != NULL)
		free(env->home);
	if (env->cmd_envp != NULL)
		free(env->cmd_envp);
	if (env->cmd != NULL)
		free(env->cmd);
	if (env->cmd_exec != NULL)
		free_temp(env->cmd_exec);
	if (args != NULL)
		free_temp(args);
	rl_clear_history();
}

void	free_token_lst(t_lst **temp)
{
	t_lst	*node;

	if ((*temp) == NULL)
		return ;
	while ((*temp) != NULL)
	{
		if ((*temp)->token->cmd)
			free((*temp)->token->cmd);
		if ((*temp)->token->option)
			free((*temp)->token->option);
		if ((*temp)->token->arg)
			free((*temp)->token->arg);
		if ((*temp)->token->redir)
			free((*temp)->token->redir);
		if ((*temp)->token)
			free((*temp)->token);
		node = (*temp)->next;
		free(*temp);
		(*temp) = node;
	}
}

int	verify_number(char *arg)
{
	int	x;

	x = 0;
	while (arg[x])
	{
		if (!ft_isdigit(arg[x]))
			return (1);
		x++;
	}
	return (0);
}
