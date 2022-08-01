/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:48:41 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/25 20:50:51 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	verify_here_redir(char **args)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (args[i])
	{
		if (right_direction(args[i]))
			return (-2);
		if (count_redir(args[i]))
			return (-2);
		if ((ft_strncmp(args[i], "<<", 2)) == 0 && (ft_strlen(args[i]) == 2))
			flag = error_redir_flag(args, i, flag);
		if ((ft_strncmp(args[i], "<", 1)) == 0 && (ft_strlen(args[i]) == 1))
			flag = error_redir_flag(args, i, flag);
		if ((ft_strncmp(args[i], ">", 1)) == 0 && (ft_strlen(args[i]) == 1))
			flag = error_redir_flag(args, i, flag);
		i++;
	}
	if (flag >= 1)
		return (1);
	if (flag == -2)
		return (-2);
	return (0);
}

int	error_redir_flag(char **args, int i, int flag)
{
	if (args[i + 1] == NULL)
		return (-2);
	else if (identity_redir(args[i + 1], args[i]) == 1)
		return (-2);
	else
	{
		if ((ft_strncmp(args[i], "<<", 2)) == 0 && (ft_strlen(args[i]) == 2))
			flag++;
	}
	return (flag);
}

int	identity_redir(char *string, char *before)
{
	if ((ft_strncmp(before, "<", 1)) == 0)
	{
		if ((ft_strncmp(string, ">", 1)) == 0)
			return (1);
	}
	if ((ft_strncmp(before, ">", 1)) == 0)
	{
		if ((ft_strncmp(string, "<", 1)) == 0)
			return (1);
	}
	return (0);
}

int	right_direction(char *string)
{
	int	i;

	i = 0;
	if (ft_strlen(string) == 2)
	{
		if (string[i] == '<')
		{
			if (string[i + 1] == '>')
				return (1);
		}
		if (string[i] == '>')
		{
			if (string[i + 1] == '<')
				return (1);
		}
	}
	return (0);
}

int	count_redir(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '<' && string[i + 1] == '<')
		{
			if (string[i + 2])
				return (1);
		}
		if (string[i] == '>' && string[i + 1] == '>')
		{
			if (string[i + 2])
				return (1);
		}
		i++;
	}
	return (0);
}
