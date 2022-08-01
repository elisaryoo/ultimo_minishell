/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:43:05 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/30 10:18:48 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_lst *temp, t_env *env, char *new)
{
	char	**elem;
	int		i;

	elem = NULL;
	if (temp->token->arg == NULL)
	{
		if (new != NULL)
			free(new);
		free_exit(temp, env, elem);
		exit(0);
	}
	else
	{
		elem = ft_split(temp->token->arg, ' ');
		i = 0;
		while (elem[i])
			i++;
		if (i > 1)
		{
			ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
			free_temp(elem);
		}
		else
			valid_exit_code(temp, env, elem, new);
	}
}

void	valid_exit_code(t_lst *temp, t_env *env, char **elem, char *old)
{
	int		verified;
	int		code;
	char	*new;

	replace_spaces(elem[0]);
	new = remove_quotes(elem[0]);
	verified = verify_number(new);
	if (verified != 0)
		exit_valid_error(elem, new);
	else
	{
		code = ft_atoi(new);
		free_exit(temp, env, elem);
		if (old != NULL)
			free(old);
		if (new != NULL)
			free(new);
		exit(code);
	}
}
