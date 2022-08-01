/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:06:51 by eryoo             #+#    #+#             */
/*   Updated: 2022/08/01 02:21:43 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	replace_spaces(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)162)
			string[i] = 32;
		if (string[i] == (char)163)
			string[i] = 124;
		if (string[i] == (char)164)
			string[i] = 62;
		if (string[i] == (char)165)
			string[i] = 60;
		if (string[i] == (char)166)
			string[i] = 36;
		if (string[i] == (char)167)
			string[i] = 36;
		i++;
	}
}

char	*remove_quotes(char *string)
{
	int		i;
	char	*new;
	t_env	env;

	i = 0;
	env.x = 0;
	env.y = 0;
	new = set_string_size(string);
	while (string[i])
	{
		if (string[i] == 34)
			in_double_quote_case(&env, string, new, i);
		else if (string[i] == 39)
			in_single_quote_case(&env, string, new, i);
		else
			new[env.y++] = string[i];
		i = localize_char_position(i, env.x);
	}
	return (new);
}

int	count_quotes(char *string)
{
	int		i;
	int		size;
	t_env	env;

	env.quote_flag = 0;
	env.x = 0;
	i = 0;
	size = ft_strlen(string);
	while (i <= size)
	{
		if (string[i] == 34)
			double_quote_found(&env, i, string);
		else if (string[i] == 39)
			single_quote_found(&env, i, string);
		i = localize_char_position(i, env.x);
	}
	return (env.quote_flag);
}

char	*set_string_size(char *string)
{
	int		count;
	int		size;
	char	*new;

	count = 0;
	size = 0;
	count = count_quotes(string);
	if (count > 0)
	{
		size = ft_strlen(string) - count + 1;
		new = (char *)ft_calloc(size, sizeof(char));
	}
	else
	{
		size = ft_strlen(string) + 1;
		new = (char *)ft_calloc(size, sizeof(char));
	}
	return (new);
}

int	check_equal_sign(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[0] != '=')
		{
			if (string[i] == '=')
			{
				string[i] = (char)162;
				return (1);
			}
			else if (check_valid_var(string[i], i) == -2)
				break ;
		}
		i++;
	}
	return (0);
}
