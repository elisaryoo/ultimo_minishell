/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:34:30 by dramos-p          #+#    #+#             */
/*   Updated: 2021/06/02 00:55:22 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		t;
	size_t		nlen;

	nlen = len;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len)
	{
		t = 0;
		while (haystack[i + t] == needle[t] && i + t < nlen)
		{
			t++;
			if (needle[t] == '\0')
			{
				return ((char *)haystack + i);
			}
		}
		i++;
		len--;
	}
	return (0);
}
