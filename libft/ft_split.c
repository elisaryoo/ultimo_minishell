/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:25:32 by dramos-p          #+#    #+#             */
/*   Updated: 2021/06/05 18:16:41 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lendelimiter(char const *s, char c)
{
	int		i;
	int		len;
	int		lenfull;

	lenfull = ft_strlen(s);
	i = 0;
	len = 0;
	while (i < lenfull)
	{
		if ((unsigned char)s[i] != (unsigned char)c)
		{
			while ((unsigned char)s[i] != (unsigned char)c && s[i])
				i++;
			len++;
		}
		i++;
	}
	return (len);
}

static int	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}

static int	ft_nalloc(char const *s, char **res, int i, char c)
{
	int		lenwords;
	int		d;

	lenwords = 0;
	while ((unsigned char)s[lenwords] != (unsigned char)c && s[lenwords])
		lenwords++;
	res[i] = (char *)ft_calloc(lenwords + 1, sizeof(char));
	if (!res[i])
		return (ft_free(res));
	d = 0;
	while (d < lenwords)
		res[i][d++] = *s++;
	return (lenwords);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		lendelimiter;
	int		lenwords;
	int		i;

	lendelimiter = ft_lendelimiter(s, c);
	res = (char **)ft_calloc((lendelimiter + 1), sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		lenwords = 0;
		if ((unsigned char)s[0] != (unsigned char)c)
		{
			lenwords = ft_nalloc(s, res, i, c);
			if (!lenwords)
				return (NULL);
			s = &s[lenwords];
			i++;
		}
		if (*s != '\0')
			s++;
	}
	return (res);
}
