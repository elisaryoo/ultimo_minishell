/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:43:11 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 17:12:45 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	unset(t_lst *temp, t_env *env)
{
	int		i;
	char	**elem;
	char	*new;

	i = 0;
	if (temp->token->arg != NULL)
	{
		elem = ft_split(temp->token->arg, ' ');
		while (elem[i] != NULL)
		{
			replace_spaces(elem[i]);
			new = remove_quotes(elem[i]);
			delete_var(new, &(env->stack));
			i++;
			if (new != NULL)
				free(new);
		}
		if (elem != NULL)
			free_temp(elem);
	}
	g_error_code = 0;
}

void	delete_var(char *var, t_var **stack)
{
	t_var	*to_del;
	t_var	*prev;

	to_del = (*stack);
	prev = NULL;
	while (to_del != NULL)
	{
		if (ft_strncmp(var, to_del->name, ft_strlen(var) + 1) == 0)
		{
			if (prev)
				prev->next = to_del->next;
			else
				(*stack) = (*stack)->next;
			free_node(to_del);
			return ;
		}
		else
		{
			prev = to_del;
			to_del = to_del->next;
		}
	}
}

void	free_node(t_var *stack)
{
	free_n_null(stack->name);
	free_n_null(stack->content);
	stack->next = NULL;
	free_n_null(stack);
}

void	free_n_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
