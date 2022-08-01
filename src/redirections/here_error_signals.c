/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_error_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:49:45 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/24 21:36:51 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delimiter_error(t_env *env, char **string)
{
	if (env->delimiter != NULL)
		free_temp(env->delimiter);
	if (string != NULL)
		free_temp(string);
	ft_putendl_fd("minishell: redirect: syntax error", STDERR_FILENO);
	env->error_code = 2;
}

void	here_doc_error(char *string)
{
	ft_putstr_fd("minishell: warning: here-document delimited by "
		"end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(string, STDERR_FILENO);
	ft_putendl_fd("`)\n", STDERR_FILENO);
}

void	stop_here_doc(int signal)
{
	(void)signal;
	g_error_code = 130;
	write(1, "\n", 1);
	free_here_docs(130);
	exit(130);
}

void	free_here_docs(int status)
{
	char	**cmd;
	int		fd[2];

	if (status == 130)
		cmd = ft_split("/usr/bin/bash bash -c 'exit 130'", ' ');
	else
		cmd = ft_split("/usr/bin/ls ls", ' ');
	pipe(fd);
	dup2(fd[1], 1);
	dup2(fd[1], 2);
	execve(cmd[0], &cmd[1], NULL);
}
