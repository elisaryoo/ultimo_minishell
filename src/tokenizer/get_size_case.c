/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:27:55 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 18:23:23 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_len_isalphanum(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) || (str[i] > 47 && str[i] < 58) || str[i] == '_')
			len++;
		else
			break ;
		i++;
	}
	return (len);
}

int	ft_chr_alpha(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			len++;
		i++;
	}
	return (len);
}

int	len_order(char *str, char c)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = FALSE;
	while (str[i] && flag == FALSE)
	{
		if (str[i] == c)
			len++;
		else
			flag = TRUE;
		i++;
	}
	return (len);
}

int	ft_len_srq(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == '>' || str[i] == '<') && str[i + 1] && str[i + 1] == ' ')
			len++;
		i++;
	}
	return (len);
}

int	get_size_custom(char **args)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (args[i] != NULL)
	{
		len = len + ft_strlen(args[i]);
		i++;
	}
	return (len);
}
