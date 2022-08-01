/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:43:03 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/30 11:25:02 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_lst *temp, t_env *env, int fd)
{
	if (temp->token->arg != NULL && temp->token->type != 5)
	{
		ft_putendl_fd("minishell: env: too many arguments", STDERR_FILENO);
		g_error_code = 1;
	}
	else
	{
		print_env(&(*env->stack), fd);
		g_error_code = 0;
	}
}

void	print_env(t_var *temp, int fd)
{
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		ft_putstr_fd(temp->name, fd);
		ft_putchar_fd('=', fd);
		if (temp->content)
			ft_putstr_fd(temp->content, fd);
		ft_putchar_fd('\n', fd);
		temp = temp->next;
	}
}
