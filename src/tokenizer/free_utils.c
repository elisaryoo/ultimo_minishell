/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:27:53 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 22:08:51 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_main(t_env *env)
{
	free_stack(&(env->stack));
	free_prompt(env);
	if (env->user != NULL)
		free(env->user);
	if (env->home != NULL)
		free(env->home);
	if (env->cmd_envp != NULL)
		free(env->cmd_envp);
	if (env->cmd != NULL)
		free(env->cmd);
	free_temp(env->paths);
	free_temp(env->cmd_exec);
	rl_clear_history();
}

void	free_prompt(t_env *env)
{
	if (env->prompt != NULL)
		free(env->prompt);
}

void	free_str(char *str)
{
	if (str != NULL)
		free(str);
}
