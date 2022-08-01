/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:14:01 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/03 14:29:25 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	size_t	offset;
	size_t	str_size;

	str_size = ft_strlen(s);
	offset = 0;
	s_cpy = malloc(str_size + 1);
	if (s_cpy == NULL)
		return (NULL);
	while (offset < str_size)
	{
		s_cpy[offset] = s[offset];
		offset++;
	}
	s_cpy[offset] = '\0';
	return (s_cpy);
}
