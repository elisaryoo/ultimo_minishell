/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:23:18 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/24 21:36:28 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**transfer_array(char **s1, char **s2)
{
	int	i;
	int	size;

	size = get_size(s2);
	size++;
	s1 = (char **)ft_calloc(size, sizeof(char *));
	i = 0;
	while (s2[i] != NULL)
	{
		s1[i] = ft_strdup(s2[i]);
		i++;
	}
	return (s1);
}

char	**input_error_check(char **args, char **elem, t_env *env)
{
	int	x;

	x = verify_here_redir(args);
	if (x == -2)
	{
		ft_putendl_fd("minishell: redirect: syntax error", STDERR_FILENO);
		g_error_code = 2;
		return (NULL);
	}
	if (x == 1)
	{
		join_here_doc(args, env);
		join_new_redir(env, args, only_here_redir(args));
		elem = transfer_array(elem, env->new_redir);
	}
	else
		elem = transfer_array(elem, args);
	return (elem);
}

void	join_new_redir(t_env *env, char **args, int size)
{
	int	x;
	int	y;

	y = size + 2;
	env->new_redir = (char **)ft_calloc(y, sizeof(char *));
	x = 0;
	y = 0;
	while (args[x] != NULL )
	{
		if ((ft_strncmp(args[x], "<<", 2)) == 0 && (ft_strlen(args[x]) == 2))
			x++;
		else
		{
			env->new_redir[y] = ft_strdup(args[x]);
			y++;
		}
		x++;
	}
	env->new_redir[y] = ft_strdup(env->new_here);
}

int	only_here_redir(char **args)
{
	int	i;
	int	count;
	int	redir;

	count = 0;
	redir = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if ((ft_strncmp(args[i], "<<", 2)) == 0 && (ft_strlen(args[i]) == 2))
		{
			redir++;
			redir++;
		}
		i++;
	}
	if (i == redir)
		return (1);
	count = i - redir;
	return (count);
}
