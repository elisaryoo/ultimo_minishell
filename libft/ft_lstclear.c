/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:20:23 by dramos-p          #+#    #+#             */
/*   Updated: 2021/06/09 00:41:24 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nlst;
	t_list	*next;

	nlst = *lst;
	while (nlst)
	{
		next = nlst->next;
		ft_lstdelone(nlst, del);
		nlst = next;
	}
	*lst = NULL;
}
