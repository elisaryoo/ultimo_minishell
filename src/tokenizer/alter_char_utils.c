/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_char_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:29:24 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 21:32:01 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	alter_char_cases(char *buf)
{
	alter_char_inquoter(buf, '\"', '|', 163);
	alter_char_inquoter(buf, '\'', '|', 163);
	alter_char_inquoter(buf, '\"', '>', 164);
	alter_char_inquoter(buf, '\'', '>', 164);
	alter_char_inquoter(buf, '\"', '<', 165);
	alter_char_inquoter(buf, '\'', '<', 165);
}

int	switch_space_char(char *buf, t_env *env)
{
	alter_dolar(buf, 166);
	if (ft_subspace(buf, 0))
	{
		ft_putendl_fd("minishell: syntax error", STDERR_FILENO);
		free_prompt(env);
		g_error_code = 2;
		return (-2);
	}
	return (0);
}
