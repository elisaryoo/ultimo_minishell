/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:11:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/25 01:07:03 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_single_io(t_env *env, int *in)
{
	env->input = *in;
	*in = STDIN_FILENO;
}

void	reset_io(int *input, int *output)
{
	if (*input != STDIN_FILENO)
		close(*input);
	if (*output != STDOUT_FILENO)
		close(*output);
	*output = STDOUT_FILENO;
}

void	set_standard_io(int *input, int *output)
{
	*input = STDIN_FILENO;
	*output = STDOUT_FILENO;
}

void	verify_redirection_io(char *string, t_env *env, int type)
{
	int			fd[2];
	static int	in;

	set_standard_io(&fd[0], &fd[1]);
	if (env->pipe_count >= 2)
	{
		pipe(fd);
		env->input = in;
		env->output = fd[1];
		in = fd[0];
		if (env->size == env->pipe_count)
			env->output = STDOUT_FILENO;
	}
	else
		set_single_io(env, &in);
	if (type == 5)
		check_redir_type(env, string, &fd[1]);
}

void	count_io(t_env *env, char **elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		if (ft_strncmp(elem[i], "<", 1) == 0)
			env->flag_in++;
		if (ft_strncmp(elem[i], ">", 1) == 0)
			env->flag_out++;
		i++;
	}
}
