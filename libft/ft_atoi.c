/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 06:49:31 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/02 16:19:59 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_atoi(const char *str)
{
	size_t	res;
	size_t	sign;
	size_t	i;
	size_t	s;

	res = 0;
	sign = 0;
	i = 0;
	s = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
		s++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
		res = res * 10 + str[i++] - '0';
	if (s > 1)
		return (0);
	if ((sign % 2) == 0)
		return (res);
	return (-res);
}
