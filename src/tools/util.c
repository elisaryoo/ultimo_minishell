/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:12:58 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/27 21:41:40 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	in_quotes(const char *str)
{
	if (str[0] == 34 && str[ft_strlen(str) - 1] == 34)
		return (2);
	else if (str[0] == 39 && str[ft_strlen(str) - 1] == 39)
		return (5);
	else
		return (FALSE);
}

int	set_quoter(int quoter)
{
	if (quoter == FALSE)
		quoter = TRUE;
	else
		quoter = FALSE;
	return (quoter);
}

int	end_arg_position(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			break ;
		i++;
	}
	return (i);
}

int	len_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isalpha(str[i]))
		i++;
	return (i);
}

char	*delete_quoter(char *str)
{
	char	*newstr;
	int		len;

	len = ft_strlen(str);
	newstr = NULL;
	if (!str)
		return (NULL);
	if (str[0] == 34 && str[len])
		newstr = ft_strdup_limit(&str[1], len - 1);
	if (str)
		free(str);
	return (newstr);
}
