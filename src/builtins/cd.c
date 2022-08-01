/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:42:59 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:06:03 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_lst *temp, t_env *env)
{
	int	ch;

	ch = verify_cd(temp, env);
	if (ch < 0)
	{
		perror("minishell: cd");
		g_error_code = 1;
	}
	else if (ch == -1)
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		g_error_code = 1;
	}
	else
	{
		update_pwd(&(env->stack), env);
		g_error_code = 0;
	}
}

int	verify_cd(t_lst *temp, t_env *env)
{
	int		ch;

	ch = 0;
	if (temp->token->arg != NULL)
		ch = locate_cd_arg(ch, temp, env);
	else
		ch = chdir(env->home);
	return (ch);
}

int	locate_cd_arg(int ch, t_lst *temp, t_env *env)
{
	int		i;
	char	**elem;
	char	*new;

	elem = ft_split(temp->token->arg, ' ');
	i = 0;
	while (elem[i] != NULL)
		i++;
	if (i > 2)
		return (-1);
	replace_spaces(elem[0]);
	new = remove_quotes(elem[0]);
	if ((ft_strncmp(new, "~", 1) == 0) \
	|| (temp->token->arg == NULL) \
	|| ((ft_strncmp(new, "--", 2) == 0) && ft_strlen(new) == 2))
		ch = chdir(env->home);
	else
		ch = chdir(new);
	if (new != NULL)
		free(new);
	free_temp(elem);
	return (ch);
}
