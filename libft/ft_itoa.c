/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:10:08 by dramos-p          #+#    #+#             */
/*   Updated: 2021/05/31 23:01:31 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lendec(int n)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = n;
	if (n <= 0)
	{
		res = res * -1;
		i++;
	}
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	size_t	str;

	str = n;
	i = ft_lendec(n);
	res = ft_calloc(sizeof(char), (i + 1));
	if (!res)
		return (0);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		str = (long long)n * -1;
		res[0] = '-';
	}
	while (str)
	{
		i--;
		res[i] = (str % 10) + '0';
		str = str / 10;
	}
	return (res);
}
