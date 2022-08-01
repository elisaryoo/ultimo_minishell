/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:30:51 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 12:28:19 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	input_redir(char **args, t_env *env)
{
	int		i;
	int		fd;
	char	**elem;

	i = 0;
	elem = NULL;
	fd = STDIN_FILENO;
	elem = input_error_check(args, elem, env);
	if (elem == NULL)
		return (-2);
	while (elem[i] != NULL)
	{
		if ((ft_strncmp(args[i], "<", 1)) == 0 && ft_strlen(args[i]) == 1)
			fd = check_infile(args[i + 1]);
		else if ((ft_strncmp(elem[i], "<<", 2)) == 0)
			fd = here_redir_case(elem[i], env, fd);
		i++;
	}
	if (elem != NULL)
		free_temp(elem);
	return (fd);
}

int	here_redir_case(char *string, t_env *env, int fd)
{
	get_delimiter(string, env);
	env->delim_size = 0;
	fd = here_doc_prompt(env, env->delimiter[0]);
	free_temp(env->delimiter);
	free_temp(env->new_redir);
	free(env->new_here);
	return (fd);
}

int	check_infile(char *file)
{
	int		fd;
	char	*new;

	replace_spaces(file);
	new = remove_quotes(file);
	fd = open(new, O_RDONLY);
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
