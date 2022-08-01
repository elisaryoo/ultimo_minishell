/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:30:53 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:40:48 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	output_redir(char **args)
{
	int	i;
	int	fd;
	int	size;
	int	x;

	x = output_error_check(args);
	if (x == -2)
		return (-2);
	i = 0;
	size = get_size(args);
	fd = STDOUT_FILENO;
	while (args[i] != NULL)
	{
		if ((ft_strncmp(args[i], ">", 1)) == 0 || \
		(ft_strncmp(args[i], ">>", 2)) == 0)
		{
			if (size <= i + 1 || args[i + 1] == NULL)
				fd = redir_error();
			else
				fd = check_outfile(args[i + 1], args[i]);
		}
		i++;
	}
	return (fd);
}

int	output_error_check(char **args)
{
	int	x;

	x = verify_here_redir(args);
	if (x == -2)
	{
		ft_putendl_fd("minishell: redirect: syntax error", STDERR_FILENO);
		g_error_code = 2;
		return (-2);
	}
	return (0);
}

int	redir_error(void)
{
	ft_putendl_fd("minishell: redirect: syntax error", STDERR_FILENO);
	g_error_code = 2;
	return (-2);
}

int	check_outfile(char *file, char *redir)
{
	int		fd;
	char	*new;

	replace_spaces(file);
	new = remove_quotes(file);
	if ((ft_strncmp(redir, ">>", 2)) == 0)
		fd = open(new, O_WRONLY | O_APPEND | O_CREAT, 0777);
	else
		fd = open(new, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		if (new != NULL)
			ft_putstr_fd(new, 2);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		g_error_code = 1;
		if (new != NULL)
			free(new);
		return (-2);
	}
	if (new != NULL)
		free(new);
	return (fd);
}
