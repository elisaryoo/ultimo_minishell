/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:20:11 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 18:41:11 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	double_quote_found(t_env *env, int i, char *string)
{
	env->quote_flag++;
	if (ft_strlen(string) == 1)
		env->x = 1;
	else
	{
		env->x = i + 1;
		if (string[env->x])
		{
			while (string[env->x] != 34 && string[env->x + 1])
				env->x++;
		}
	}
	if (string[env->x] == 34)
		env->quote_flag++;
}

void	single_quote_found(t_env *env, int i, char *string)
{
	env->quote_flag++;
	if (ft_strlen(string) == 1)
		env->x = 1;
	else
	{
		env->x = i + 1;
		if (string[env->x])
		{
			while (string[env->x] != 39 && string[env->x + 1])
				env->x++;
		}
	}
	if (string[env->x] == 39)
		env->quote_flag++;
}

int	localize_char_position(int i, int x)
{
	if (x > i)
	{
		i = x;
		i++;
	}
	else
		i++;
	return (i);
}

void	in_double_quote_case(t_env *env, char *string, char *new, int i)
{
	if (ft_strlen(string) == 1)
		env->x = 1;
	else
	{
		env->x = i + 1;
		if (string[env->x])
		{
			while (string[env->x] != 34 && string[env->x + 1])
				new[env->y++] = string[env->x++];
		}
	}
}

void	in_single_quote_case(t_env *env, char *string, char *new, int i)
{
	if (ft_strlen(string) == 1)
		env->x = 1;
	else
	{
		env->x = i + 1;
		if (string[env->x])
		{
			while (string[env->x] != 39 && string[env->x + 1])
				new[env->y++] = string[env->x++];
		}
	}
}
