/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:38:32 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 21:41:44 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initialize(t_env *env)
{
	env->cmd_envp = NULL;
	env->cmd = NULL;
	env->paths = NULL;
	env->cmd_exec = NULL;
}

void	initialize_counter(t_env *env)
{
	env->y = 0;
	env->i = 0;
}

void	prompt_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int signum)
{
	(void)signum;
	g_error_code = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	log_out(int signum)
{
	(void)signum;
	g_error_code = 131;
	write(1, "\n", 1);
	rl_clear_history();
	ft_putendl_fd("Quit (core dumped)", 1);
}
