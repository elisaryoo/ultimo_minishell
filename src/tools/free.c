/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:15:06 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/31 17:54:06 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_temp(char **temp)
{
	int	y;

	y = 0;
	if (temp == NULL)
		return ;
	while (temp[y])
	{
		if (temp[y])
			free(temp[y]);
		y++;
	}
	if (temp)
		free(temp);
}

void	free_temp_q(char **temp, int size)
{
	if (temp == NULL)
		return ;
	while (size)
	{
		if (temp[size])
			free(temp[size]);
		size--;
	}
	if (temp)
		free(temp);
}
