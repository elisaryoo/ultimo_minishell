/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:41:40 by eryoo             #+#    #+#             */
/*   Updated: 2022/08/01 02:02:19 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_valid_var(char new, int i)
{
	if (i == 0)
	{
		if (ft_isalpha(new) != 1024 && new != '_')
			return (-2);
	}
	else
	{
		if (ft_isalnum(new) != 1 && new != '_')
			return (-2);
	}
	return (0);
}

void	check_double(char *var, t_var *temp, t_env *env)
{
	char	**split;
	int		i;
	int		double_flag;

	double_flag = 0;
	i = 0;
	split = ft_split(var, (char)162);
	while (split[i])
		i++;
	while (temp != NULL)
	{
		if (ft_strncmp(split[0], temp->name, ft_strlen(split[0]) + 1) == 0)
		{
			free(temp->content);
			if (i > 1)
				temp->content = ft_strdup(split[1]);
			else
				temp->content = ft_strdup("");
			double_flag++;
		}
		temp = temp->next;
	}
	add_new_env(i, double_flag, env, split);
	free_temp(split);
}

void	add_new_env(int i, int flag, t_env *env, char **arg)
{
	if (flag == 0)
	{
		if (i > 1)
			add_to_stack(env, arg[0], arg[1]);
		else
			add_to_stack(env, arg[0], "");
	}
}
