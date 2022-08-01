/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 23:02:07 by dramos-p          #+#    #+#             */
/*   Updated: 2021/05/28 17:09:58 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*news;
	unsigned int	c;

	c = ft_strlen(s);
	if (!start && len > c)
	{
		news = (char *)ft_calloc(sizeof(char), c);
		ft_strlcpy(news, s, len + 1);
		return (news);
	}
	if (!len || !s || start > c)
		return (news = (char *)ft_calloc(sizeof(char), 1));
	news = (char *)ft_calloc(sizeof(char), len + 1);
	if (!news)
		return (NULL);
	ft_strlcpy(news, s + start, len + 1);
	return (news);
}
