/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_char_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:27:10 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 18:19:40 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	alter_dolar(char *str, int s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '$' && str[i + 1] && str[i + 1] == 32) || \
		(str[i] == '$' && !str[i + 1]))
			str[i] = s;
		if ((str[i] == '$' && str[i + 1] && str[i + 1] == 34) || \
		(str[i] == '$' && !str[i + 1]))
			str[i] = s;
		if ((str[i] == '$' && str[i + 1] && str[i + 1] == 39) || \
		(str[i] == '$' && !str[i + 1]))
			str[i] = s;
		i++;
	}
}

void	alter_char_inquotert(char *str, char c, int s)
{
	int	i;
	int	y;

	i = 0;
	y = FALSE;
	while (str[i])
	{
		if (str[i] == '\'' && y == FALSE)
		{
			y = TRUE;
			i++;
			continue ;
		}
		if (str[i] == '\'' && y == TRUE)
		{
			y = FALSE;
			i++;
			continue ;
		}
		if (y == TRUE && str[i] == c)
			str[i] = s;
		i++;
	}
}

void	alter_char_inquoter(char *str, char q, char c, int s)
{
	int	i;
	int	y;

	i = 0;
	y = FALSE;
	while (str[i])
	{
		if (str[i] == q && y == FALSE)
		{
			y = TRUE;
			i++;
			continue ;
		}
		if (str[i] == q && y == TRUE)
		{
			y = FALSE;
			i++;
			continue ;
		}
		if (y == TRUE && str[i] == c)
			str[i] = s;
		i++;
	}
}

void	alter_char(char *str, char c, char s)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = s;
		i++;
	}
}

char	*alter_value(char **tmp, char *uni, int i, t_env *env)
{
	char	**aux;

	aux = NULL;
	if (tmp[i][0] == '$')
		env->flag = FALSE;
	else
		env->flag = TRUE;
	if (len_c(tmp[i], '$') && in_quotes(tmp[i]) != 5)
	{
		aux = ft_split(tmp[i], '$');
		if (aux)
		{
			if (uni != NULL)
				free(uni);
			uni = check_variable(&(*env), aux);
			free(tmp[i]);
			tmp[i] = ft_strdup(uni);
		}
		if (aux)
			free(aux);
	}
	return (uni);
}
