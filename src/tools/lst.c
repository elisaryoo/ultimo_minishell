/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:13:29 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/25 01:37:50 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lst	*lst_new(t_token *data)
{
	t_lst	*elem;

	elem = (t_lst *)malloc(sizeof(t_lst));
	if (!elem)
		return (NULL);
	elem->token = (t_token *)malloc(sizeof(t_token));
	ft_init_token(elem->token);
	if (data->arg)
		elem->token->arg = ft_strdup(data->arg);
	if (data->cmd)
		elem->token->cmd = ft_strdup(data->cmd);
	if (data->option)
		elem->token->option = ft_strdup(data->option);
	if (data->redir)
		elem->token->redir = ft_strdup(data->redir);
	if (data->type)
		elem->token->type = data->type;
	elem->next = NULL;
	return (elem);
}

t_lst	*lst_last_data(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*p;

	if (*lst)
	{
		p = lst_last_data(*lst);
		p->next = new;
	}
	else
		*lst = new;
}

void	lst_clear(t_lst **lst)
{
	t_lst	*nlst;
	t_lst	*next;

	nlst = *lst;
	while (nlst)
	{
		next = nlst->next;
		free_token(nlst->token);
		free(nlst);
		nlst = next;
	}
	*lst = NULL;
}

int	qto_lst(t_lst *x)
{
	int	i;

	i = 0;
	while (x)
	{
		i++;
		x = x->next;
	}
	return (i);
}
