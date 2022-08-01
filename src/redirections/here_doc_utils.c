/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:12:51 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:47:04 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	join_here_doc(char **args, t_env *env)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (args[i] != NULL)
	{
		if ((ft_strncmp(args[i], "<<", 2)) == 0 && (ft_strlen(args[i]) == 2))
		{
			if (flag == 0)
			{
				join_all_here(args, i, env, flag);
				flag++;
			}
			else
				join_all_here(args, i, env, flag);
		}
		i++;
	}
}

void	join_all_here(char **args, int i, t_env *env, int flag)
{
	char	*subs;
	char	*redir;
	char	*temp;
	char	*old;

	redir = ft_strjoin(args[i], " ");
	temp = ft_strjoin(args[i + 1], " ");
	subs = ft_strjoin(redir, temp);
	if (flag > 0)
	{
		old = ft_strjoin(env->new_here, subs);
		free(env->new_here);
		env->new_here = ft_strdup(old);
		free(temp);
		free(redir);
		free(subs);
		free(old);
	}
	else
	{
		env->new_here = ft_strdup(subs);
		free(temp);
		free(redir);
		free(subs);
	}
}

void	transfer_all_delimiter(char **elem, t_env *env, int size)
{
	int		i;
	int		x;
	char	*new;

	i = 0;
	x = 0;
	while (elem[i] != NULL)
	{
		if ((ft_strncmp(elem[i], "<<", 2)) == 0)
		{
			if (size <= i + 1 || (ft_strncmp(elem[i + 1], "<", 1)) == 0)
				delimiter_error(env, elem);
			else
			{
				replace_spaces(elem[i + 1]);
				new = remove_quotes(elem[i + 1]);
				env->delimiter[x] = ft_strdup(new);
				if (new != NULL)
					free(new);
				x++;
			}
		}
		i++;
	}
}

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}
