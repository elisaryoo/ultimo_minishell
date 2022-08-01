/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_case_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:38:39 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 21:41:38 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*insert_space(char *str, char c)
{
	t_env	env;
	int		size;
	char	*newstr;

	env.i = len_c(str, c);
	size = ft_strlen(str) + (env.i * 2);
	newstr = (char *)malloc((size + 1) * sizeof(char));
	initialize_counter(&env);
	while (str[env.i])
	{
		if (verify_same_char(str, newstr, c, &env) == 1)
			continue ;
		if (verify_diff_char(str, newstr, c, &env) == 1)
			continue ;
		if (verify_next_same_char(str, newstr, c, &env) == 1)
			continue ;
		if (verify_next_diff_char(str, newstr, c, &env) == 1)
			continue ;
		newstr[env.y] = str[env.i];
		env.y++;
		env.i++;
	}
	newstr[env.y] = '\0';
	free(str);
	return (newstr);
}

int	verify_same_char(char *str, char *newstr, char c, t_env *env)
{
	if (str[env->i] == c && str[env->i + 1] == c)
	{
		newstr[env->y++] = str[env->i];
		env->i++;
		return (1);
	}
	return (0);
}

int	verify_diff_char(char *str, char *newstr, char c, t_env *env)
{
	if (str[env->i] == c && str[env->i + 1] != c)
	{
		newstr[env->y++] = str[env->i];
		newstr[env->y++] = ' ';
		env->i++;
		return (1);
	}
	return (0);
}

int	verify_next_same_char(char *str, char *newstr, char c, t_env *env)
{
	if (str[env->i + 1] && str[env->i + 1] == c && \
	str[env->i + 2] && str[env->i + 2] == c)
	{
		newstr[env->y++] = str[env->i];
		newstr[env->y++] = ' ';
		newstr[env->y++] = c;
		newstr[env->y++] = c;
		newstr[env->y++] = ' ';
		env->i = env->i + 3;
		return (1);
	}
	return (0);
}

int	verify_next_diff_char(char *str, char *newstr, char c, t_env *env)
{
	if (str[env->i + 1] && str[env->i + 1] == c && \
	str[env->i + 2] && str[env->i + 2] != c)
	{
		newstr[env->y++] = str[env->i];
		newstr[env->y++] = ' ';
		newstr[env->y++] = c;
		newstr[env->y++] = ' ';
		env->i = env->i + 2;
		return (1);
	}
	return (0);
}
