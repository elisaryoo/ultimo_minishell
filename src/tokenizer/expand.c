/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:27:51 by eryoo             #+#    #+#             */
/*   Updated: 2022/08/01 01:13:15 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env(t_var *temp, char *str)
{
	if (!str)
		return (NULL);
	if (temp == NULL)
		printf("this stack is empty\n");
	while (temp != NULL)
	{
		if (ft_strncmp(str, temp->name, (ft_len_isalphanum(str) + 1)) == 0)
			return (temp->content);
		temp = temp->next;
	}
	return (NULL);
}

char	*ft_expand(t_env *env, char *str)
{
	char	*exp;
	char	*env_value;
	char	*tmp;

	tmp = str;
	if (str[0] == 39)
		return (0);
	if (str[ft_strlen(str) - 1] && str[ft_strlen(str) - 1] == 34)
		exp = ft_strdup_limit(str, ft_len_isalphanum(str));
	else
		exp = ft_strdup_limit(str, ft_len_isalphanum(str));
	env_value = NULL;
	ft_expand_aux(str, env, exp, &env_value);
	str = tmp;
	free(exp);
	if (env_value)
		return (env_value);
	else
		return (ft_strdup(""));
}

char	**expand(t_env *env, char *str)
{
	char	**tmp;
	char	*uni;
	int		i;

	tmp = ft_split(str, ' ');
	i = 0;
	uni = NULL;
	if (tmp)
	{
		while (tmp[i])
		{
			uni = alter_value(tmp, uni, i, env);
			i++;
		}
	}
	if (uni)
		free(uni);
	return (tmp);
}

char	*check_variable(t_env *env, char **aux)
{
	char	*uni;
	int		y;

	y = 0;
	uni = NULL;
	while (aux[y])
	{
		if (env->flag)
		{
			env->flag = 0;
			uni = ft_merge(uni, aux[y]);
			free(aux[y++]);
			continue ;
		}
		if (ft_strncmp(aux[y], "?", 1) == 0 && env->flag == 0)
		{
			uni = check_error_code(aux[y++], uni);
			continue ;
		}
		check_variable_aux(env, &aux[y], &uni);
		y++;
	}
	return (uni);
}
