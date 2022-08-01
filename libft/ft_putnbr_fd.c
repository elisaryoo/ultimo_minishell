/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:22:48 by dramos-p          #+#    #+#             */
/*   Updated: 2021/06/01 22:02:27 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	v_div(long int num)
{
	long int	count;
	long int	result;

	result = 10;
	count = 1;
	while (count < num)
	{
		result = result * 10;
		count++;
	}
	return (result / 10);
}

static long int	qto_casas(long int x)
{
	long int	casas;

	casas = 0;
	while (x > 0)
	{
		x = x / 10;
		casas++;
	}
	return (casas);
}

static long int	ft_is_negative(long int n)
{
	long int	resp;

	if (n >= 0)
		resp = 1;
	else
		resp = 0;
	return (resp);
}

static void	calc_print(long int qto_d, long int nb2, int fd)
{
	long int	el;
	long int	resultado;
	long int	conta;

	while (qto_d > 0)
	{
		el = v_div(qto_d);
		conta = nb2 / el;
		resultado = conta + '0';
		write(fd, &resultado, 1);
		nb2 = nb2 - el * conta;
		qto_d--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	qto_d;
	long int	nb2;

	nb2 = n;
	if (n == 0)
		write(fd, "0", 1);
	else if (ft_is_negative(nb2) == 0)
	{
		write(fd, "-", 1);
		nb2 = nb2 * (-1);
	}
	qto_d = qto_casas(nb2);
	calc_print(qto_d, nb2, fd);
}
