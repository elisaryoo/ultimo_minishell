/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:26:28 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/31 01:14:06 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 

int	len_c(char *arg, int quote)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (arg[i] == quote)
			len++;
		i++;
	}
	return (len);
}

int	char_position(char *arg, int c)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (arg[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*remont_str(char **sort)
{
	int		i;
	char	*uni;
	int		len;

	i = 0;
	uni = NULL;
	len = get_size(sort) - 1;
	while (sort[i])
	{
		uni = ft_merge(uni, sort[i]);
		if (len > i)
			uni = ft_merge(uni, " ");
		i++;
	}
	if (sort)
		free_temp(sort);
	return (uni);
}

char	*ft_merge(char *uni, char *temp)
{
	char	*tmp;
	char	*aux;

	tmp = NULL;
	aux = NULL;
	if (!temp)
		aux = ft_strdup("");
	else
		aux = ft_strdup(temp);
	if (uni == NULL)
		return (aux);
	tmp = ft_strjoin(uni, aux);
	if (uni)
		free(uni);
	free(aux);
	return (tmp);
}
