/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:29:32 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/30 05:37:29 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*current_path(t_var **stack, t_env *env)
{
	t_var	*temp;

	temp = (*stack);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "PWD", 3) == 0)
		{
			env->path = ft_strdup(temp->content);
		}
		temp = temp->next;
	}
	return (env->path);
}

void	get_user(t_var **stack, t_env *env)
{
	t_var	*temp;

	temp = (*stack);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "USER", 4) == 0)
		{
			env->user = ft_strdup(temp->content);
		}
		temp = temp->next;
	}
}

char	*update_prompt(t_env *env)
{
	int		length;
	char	*true_prom;
	char	*path;

	define_prompt(env);
	path = current_path(&(env->stack), env);
	length = ft_strlen(env->magenta) + ft_strlen(env->user) \
			+ ft_strlen(env->middle) \
			+ ft_strlen(env->cyan) + ft_strlen(path) + ft_strlen(env->end) \
			+ ft_strlen(env->reset);
	true_prom = ft_calloc(length + 1, sizeof(char));
	ft_strlcat(true_prom, env->magenta, length);
	ft_strlcat(true_prom, env->user, length);
	ft_strlcat(true_prom, env->middle, length);
	ft_strlcat(true_prom, env->cyan, length);
	ft_strlcat(true_prom, path, length);
	ft_strlcat(true_prom, env->end, length);
	ft_strlcat(true_prom, env->reset, length);
	env->prompt = ft_strdup(true_prom);
	free(path);
	free(true_prom);
	return (env->prompt);
}

void	define_prompt(t_env *env)
{
	env->magenta = MAGENTA;
	env->cyan = CYAN;
	env->middle = " \001🐧\002 ";
	env->end = "\001$\002 ";
	env->reset = RESET;
}

void	get_home(t_var **stack, t_env *env)
{
	t_var	*temp;

	temp = *(stack);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "HOME", 4) == 0)
		{
			env->home = ft_strdup(temp->content);
			break ;
		}
		temp = temp->next;
	}
}
