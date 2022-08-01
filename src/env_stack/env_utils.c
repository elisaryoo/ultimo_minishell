/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:38:24 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:34:04 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_var	*ft_lstnew_env(char *name, char *content)
{
	t_var	*elem;

	elem = (t_var *)ft_calloc(1, sizeof(t_var));
	if (!elem)
		return (NULL);
	elem->name = ft_strdup(name);
	elem->content = ft_strdup(content);
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back_env(t_var **lst, t_var *new)
{
	t_var	*p;

	if (*lst)
	{
		p = ft_lstlast_env(*lst);
		p->next = new;
	}
	else
		*lst = new;
}

t_var	*ft_lstlast_env(t_var *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
