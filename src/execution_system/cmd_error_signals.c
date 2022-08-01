/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:42:13 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/24 23:48:34 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execve_signal(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}

void	quit_process(int signal)
{
	(void)signal;
	g_error_code = 131;
	ft_putendl_fd("Quit (core dumped)", 1);
}

void	interrupt_process(int signal)
{
	(void)signal;
	g_error_code = 130;
	write(1, "\n", 1);
}

void	exec_error(char *cmd, t_env *env)
{
	g_error_code = 127;
	if (ft_strncmp(cmd, "$?", 2) == 0)
	{
		free(cmd);
		cmd = ft_itoa(g_error_code);
	}
	ft_putstr_fd("minishell: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd, 2);
	write(2, "\n", 1);
	reset_io(&env->input, &env->output);
}

void	define_exec_error(int exec)
{
	if (exec)
	{
		if (g_error_code != 131 && g_error_code != 130)
			if (WIFEXITED(exec))
			g_error_code = WEXITSTATUS(exec);
	}
	else
	{
		if (g_error_code != 130)
			g_error_code = 0;
	}
}
