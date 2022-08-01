/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:45:46 by eryoo             #+#    #+#             */
/*   Updated: 2022/08/01 00:39:49 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*del_space(char *str)
{
	int		i;
	int		y;
	int		size;
	char	*newstr;

	i = len_c(str, 32);
	size = ft_strlen(str) - i;
	newstr = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != 32)
		{
			newstr[y] = str[i];
			y++;
		}
		i++;
	}
	newstr[y] = '\0';
	return (newstr);
}

char	*ft_del_srq(char *str)
{
	char	*newstr;
	int		x[4];

	x[0] = ft_strlen(str) - ft_len_srq(str);
	if (!x[0])
		return (NULL);
	newstr = (char *)ft_calloc((x[0] + 1), sizeof(char));
	x[1] = 0;
	x[2] = 0;
	x[3] = 1;
	while (str[x[1]])
	{
		if (x[3])
		{
			newstr[x[2]] = str[x[1]];
			x[2]++;
		}
		if ((str[x[1]] == '>' || str[x[1]] == '<' || str[x[1]] == ' ') \
		&& str[x[1] + 1] == ' ')
			x[3] = 0;
		else
			x[3] = 1;
		x[1]++;
	}
	return (newstr);
}

void	aux_reorder(t_sort *x, char **sort, int i)
{
	if (sort[i][0] == '<' || sort[i][0] == '>')
	{
		x->redir = ft_merge(x->redir, sort[i]);
		x->redir = ft_merge(x->redir, " ");
	}
	else
	{
		x->cmd = ft_merge(x->cmd, sort[i]);
		x->cmd = ft_merge(x->cmd, " ");
	}
}
