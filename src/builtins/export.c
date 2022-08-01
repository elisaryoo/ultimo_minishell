/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:43:07 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 17:11:42 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export(t_lst *temp, t_env *env, int fd)
{
	if (temp->token->arg == NULL)
		print_declare(&(*env->stack), fd);
	else if ((ft_strlen(temp->token->arg) == 0) && (temp->token->type == 5))
		print_declare(&(*env->stack), fd);
	else
		export_valid_var(temp, env);
	g_error_code = 0;
}

void	export_valid_var(t_lst *temp, t_env *env)
{
	int		i;
	char	**elem;
	char	*new;

	i = 0;
	elem = ft_split(temp->token->arg, ' ');
	while (elem[i] != NULL)
	{
		replace_spaces(elem[i]);
		new = remove_quotes(elem[i]);
		if (check_equal_sign(new))
			check_double(new, &(*env->stack), env);
		else
		{
			ft_putendl_fd("minishell: export: not a valid identifier", \
			STDERR_FILENO);
			g_error_code = 2;
		}
		if (new != NULL)
			free(new);
		i++;
	}
	free_temp(elem);
}

void	print_declare(t_var *temp, int fd)
{
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(temp->name, fd);
		ft_putchar_fd('=', fd);
		ft_putchar_fd('"', fd);
		if (temp->content)
		{
			ft_putstr_fd(temp->content, fd);
			ft_putchar_fd('"', fd);
		}
		ft_putchar_fd('\n', fd);
		temp = temp->next;
	}
}
