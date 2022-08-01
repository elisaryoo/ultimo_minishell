/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_custom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:15:49 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/25 02:07:10 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup_limit(const char *s, size_t i)
{
	char	*s_cpy;
	size_t	offset;

	offset = 0;
	s_cpy = malloc(i + 1);
	if (s_cpy == NULL)
		return (NULL);
	while (offset < i)
	{
		s_cpy[offset] = s[offset];
		offset++;
	}
	s_cpy[offset] = '\0';
	return (s_cpy);
}

char	*split_arg(char *str)
{
	int		i;
	char	*aux;
	int		quoter;
	int		signal;

	i = 0;
	quoter = 0;
	signal = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			quoter = set_quoter(quoter);
		if (str[i] == 60 || str[i] == 62)
			signal = TRUE;
		if (signal == TRUE && quoter == FALSE)
			break ;
		i++;
	}
	aux = (char *)ft_calloc((i + 3), sizeof(char));
	ft_strlcpy(aux, str, i + 1);
	return (aux);
}
