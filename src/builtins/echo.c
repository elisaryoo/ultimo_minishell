/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:43:01 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:08:18 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(t_lst *temp, int fd)
{
	char	**elem;
	int		i;
	int		size;

	i = 0;
	elem = NULL;
	if (temp->token->arg == NULL)
		ft_putchar_fd('\n', fd);
	else
	{
		elem = ft_split(temp->token->arg, ' ');
		size = get_size(elem);
		while (elem[i])
		{
			print_echo(elem[i], fd, size, i);
			i++;
		}
		if (temp->token->option == NULL)
			ft_putchar_fd('\n', fd);
		free_temp(elem);
	}
	g_error_code = 0;
}

void	print_echo(char *string, int fd, int size, int i)
{
	char	*new;

	new = NULL;
	replace_spaces(string);
	new = remove_quotes(string);
	ft_putstr_fd(new, fd);
	if (size - 1 != i)
		ft_putchar_fd(' ', fd);
	if (new != NULL)
		free(new);
}
