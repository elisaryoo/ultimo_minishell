/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:13:29 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/30 04:19:44 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isredir(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_isbuiltin(char *str)
{
	if (ft_strncmp(str, "echo", ft_strlen(str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(str, "cd", ft_strlen(str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(str, "pwd", ft_strlen(str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(str, "export", ft_strlen(str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(str, "unset", ft_strlen(str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(str, "env", ft_strlen(str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(str, "exit", ft_strlen(str) + 1) == 0)
		return (TRUE);
	return (FALSE);
}

char	*set_expand(char *env_value, char *str)
{
	char	*uni;

	if (!env_value)
		return (NULL);
	if (len_alpha(str) == (int)ft_strlen(str))
		uni = ft_strdup(env_value);
	else if (!env_value && ft_strlen(str))
		uni = ft_strdup(str);
	else if (env_value == NULL)
		uni = env_value;
	else
		uni = ft_strjoin(env_value, str);
	return (uni);
}
