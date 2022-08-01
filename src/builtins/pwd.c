/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:43:09 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:31:15 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwd(int fd)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_putendl_fd("minishell: pwd: unable to fetch current dir", \
		STDERR_FILENO);
		g_error_code = 2;
	}
	else
	{
		ft_putendl_fd(cwd, fd);
		g_error_code = 0;
	}
}

void	update_pwd(t_var **stack, t_env *env)
{
	t_var	*temp;
	char	*old;
	char	pwd[256];

	temp = (*stack);
	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		perror("minishell: cd");
		g_error_code = 1;
	}
	else
	{
		while (temp != NULL)
		{
			if (ft_strncmp(temp->name, "PWD", 3) == 0)
			{
				old = ft_strdup(temp->content);
				update_oldpwd(&(env->stack), old);
				free(temp->content);
				temp->content = ft_strdup(pwd);
				free(old);
			}
			temp = temp->next;
		}
	}
}

void	update_oldpwd(t_var **stack, char *old)
{
	t_var	*temp;

	temp = *(stack);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "OLDPWD", 6) == 0)
		{
			free(temp->content);
			temp->content = ft_strdup(old);
		}
		temp = temp->next;
	}
}

void	get_oldpwd(t_var **stack, t_env *env)
{
	t_var	*temp;

	temp = *(stack);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "OLDPWD", 6) == 0)
		{
			env->old_pwd = ft_strdup(temp->content);
			break ;
		}
		temp = temp->next;
	}
}
