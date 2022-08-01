/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:53:46 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:25:59 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_single_builtin(t_lst *temp, t_env *env, char *new)
{
	if (ft_strncmp(new, "cd", ft_strlen(new)) == 0)
		ft_cd(temp, env);
	else if (ft_strncmp(new, "export", ft_strlen(new)) == 0)
		export(temp, env, env->output);
	else if (ft_strncmp(new, "unset", ft_strlen(new)) == 0)
		unset(temp, env);
	else if (ft_strncmp(new, "env", ft_strlen(new)) == 0)
		ft_env(temp, env, env->output);
	else if (ft_strncmp(new, "pwd", ft_strlen(new)) == 0)
		pwd(env->output);
	else if (ft_strncmp(new, "exit", ft_strlen(new)) == 0)
		ft_exit(temp, env, new);
	else if (ft_strncmp(new, "echo", ft_strlen(new)) == 0)
		echo(temp, env->output);
	else
		return (1);
	return (0);
}
