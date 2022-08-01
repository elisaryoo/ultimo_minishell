/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:36:18 by dramos-p          #+#    #+#             */
/*   Updated: 2021/05/19 00:59:09 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c_dst;
	size_t	c_src;

	c_dst = ft_strlen(dst);
	c_src = ft_strlen(src);
	i = 0;
	if (dstsize < c_dst + 1)
		return (dstsize + c_src);
	if (dstsize > c_dst + 1)
	{
		while (src[i] != '\0' && c_dst + 1 + i < dstsize)
		{
			dst[c_dst + i] = src[i];
			i++;
		}
	}
	dst[c_dst + i] = '\0';
	return (c_dst + c_src);
}
