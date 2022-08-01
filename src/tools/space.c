/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:13:23 by dramos-p          #+#    #+#             */
/*   Updated: 2022/08/01 02:22:10 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_next_quoter(char *item, int quoter)
{
	int	i;

	i = 1;
	while (item[i])
	{
		if (item[i] == quoter)
			return (i);
		i++;
	}
	return (i);
}

int	comp_position(char *item, int len, t_position *x)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	x->end = -1;
	x->start = -1;
	while (item[i] != '\0' && len)
	{
		if ((item[i] == 39 && flag == 0) || (item[i] == 34 && flag == 0))
		{
			flag = (int)item[i];
			x->start = i;
			i++;
			len--;
			if (len_c(&item[i], flag))
				x->end = get_next_quoter(&item[i], flag) + i;
			continue ;
		}
		i++;
		len--;
	}
	return (flag);
}

t_position	set_position_quoter(char *item)
{
	int				flag;
	int				i;
	int				len;
	t_position		x;

	i = 0;
	flag = 0;
	x.flag = 0;
	len = ft_strlen(item);
	flag = comp_position(item, len, &x);
	if ((flag == 0 && !item[i]) || !item)
		x.flag = 1;
	return (x);
}

void	alter_space(char *str, t_position x)
{
	int	i;

	i = x.start;
	while (str[i] && i < x.end)
	{
		if (str[i] == 32)
			str[i] = (char)162;
		i++;
	}
}

int	ft_subspace(char *str, int y)
{
	t_position	x;
	int			check;

	check = count_quotes(str);
	x = set_position_quoter(str);
	if (x.start > -1 && x.end < 0)
		y = 1;
	if (x.start > -1 && x.end > -1)
	{
		alter_space(&(*str), x);
		if (x.end && str[x.end])
			y = ft_subspace(&str[x.end + 1], y);
	}
	if (check % 2 == 0)
	{
		return (0);
	}
	return (y);
}
