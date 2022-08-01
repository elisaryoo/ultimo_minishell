/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:27:51 by eryoo             #+#    #+#             */
/*   Updated: 2022/08/01 01:15:43 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_expand_aux(char *str, t_env *env, char *exp, char **env_value)
{
	int		i;

	if ((int)ft_strlen(str) > ft_len_isalphanum(str))
	{
		i = ft_len_isalphanum(&str[0]) + 1;
		while (--i)
			str++;
		if (get_env(&(*env->stack), exp))
			*env_value = ft_strdup(get_env(&(*env->stack), exp));
		else
			*env_value = ft_strdup("");
		if (&str[0])
			*env_value = ft_merge(*env_value, &str[0]);
	}
	else
	{
		if (get_env(&(*env->stack), exp))
			*env_value = ft_strdup(get_env(&(*env->stack), exp));
		else
			*env_value = ft_strdup("");
		*env_value = ft_merge(*env_value, "");
	}
}

void	check_variable_aux(t_env *env, char **aux, char **uni)
{
	char	*temp;

	temp = NULL;
	if (*aux[0] == 34)
		*uni = ft_merge(*uni, *aux);
	else
	{
		temp = ft_expand(&(*env), *aux);
		*uni = ft_merge(*uni, temp);
		if (temp)
			free(temp);
	}
	if (*aux)
		free(*aux);
}
