/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:42:24 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/24 20:40:31 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_to_stack(t_env *env, char **envp)
{
	char	**temp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	env->stack = NULL;
	while (envp[i])
	{
		env->length = ft_strlen(envp[i]);
		temp = ft_split(envp[i], '=');
		while (temp[x])
			x++;
		if (x > 2)
			split_once(env, temp, x);
		else
			add_to_stack(env, temp[0], temp[1]);
		free_temp2(temp);
		x = 0;
		i++;
	}
}

void	add_to_stack(t_env *env, char *name, char *content)
{
	if (content == NULL)
		content = " ";
	ft_lstadd_back_env(&(env->stack), ft_lstnew_env(name, content));
}

void	split_once(t_env *env, char **temp, int x)
{
	int		size;
	char	*buffer;

	size = 2;
	buffer = malloc(env->length * sizeof(char *));
	ft_strlcpy(buffer, temp[1], x);
	while (size < x)
	{
		ft_strlcat(buffer, "=", env->length);
		ft_strlcat(buffer, temp[size], env->length);
		size++;
	}
	add_to_stack(env, temp[0], buffer);
	free(buffer);
}

void	free_stack(t_var **stack)
{
	t_var	*temp;

	if ((*stack) == NULL)
		return ;
	while ((*stack) != NULL)
	{
		if ((*stack)->name)
			free((*stack)->name);
		if ((*stack)->content)
			free((*stack)->content);
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}

void	free_temp2(char **temp)
{
	int	y;

	y = 0;
	if (temp == NULL)
		return ;
	while (temp[y])
	{
		free(temp[y]);
		y++;
	}
	free(temp);
}
