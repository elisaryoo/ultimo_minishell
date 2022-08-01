/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:54:35 by dramos-p          #+#    #+#             */
/*   Updated: 2021/05/22 18:00:03 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	proc;

	proc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == proc)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == proc)
		return ((char *)s + i);
	return (0);
}
