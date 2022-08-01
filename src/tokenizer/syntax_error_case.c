/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:45:48 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 21:33:10 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	put_perror(void)
{
	ft_putendl_fd("minishell: syntax error", STDERR_FILENO);
	g_error_code = 2;
}

void	syntax_error(char *str, t_env *env)
{
	if (str != NULL)
		free(str);
	free_prompt(env);
	put_perror();
}
