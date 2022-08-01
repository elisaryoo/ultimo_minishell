/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:38:37 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 21:42:38 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax_rr(char *x)
{
	int	i;

	i = 0;
	while (x[i])
	{
		if ((x[i] == '>' && x[i + 1] && x[i + 1] == '>') || \
		(x[i] == '>' && !x[i + 1]))
			return (TRUE);
		if ((x[i] == '<' && x[i + 1] && x[i + 1] == '<') || \
		(x[i] == '<' && !x[i + 1]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	check_syntax_ra(char *x)
{
	int	i;

	i = 0;
	while (x[i])
	{
		if (x[i] == '>' && x[i + 1] && x[i + 1] == '<')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	check_syntax_rb(char *x)
{
	int	i;

	i = 0;
	while (x[i])
	{
		if (x[i] == '<' && x[i + 1] && x[i + 1] == '>')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*reorder_str(char *str)
{
	char	*tmp;
	char	**sort;
	char	*newstr;
	int		i;
	t_sort	x;

	x.cmd = NULL;
	x.redir = NULL;
	newstr = NULL;
	tmp = ft_del_srq(str);
	sort = ft_split(tmp, ' ');
	i = 0;
	while (sort[i])
	{
		aux_reorder(&x, sort, i);
		i++;
	}
	newstr = ft_merge(x.cmd, x.redir);
	newstr = insert_space(newstr, '>');
	newstr = insert_space(newstr, '<');
	free(x.redir);
	free_temp(sort);
	free(tmp);
	return (newstr);
}
