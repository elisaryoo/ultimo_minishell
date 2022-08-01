/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:38:35 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 22:08:45 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax_pipe(char *x)
{
	int	i;

	i = 0;
	while (x[i])
	{
		if ((x[i] == '|' && x[i + 1] && x[i + 1] == '|') || \
		(x[i] == '|' && !x[i + 1]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	check_syntax(char *x, t_env *env)
{
	char	*str;
	int		len;

	len = ft_strlen(x) - len_c(x, ' ');
	if (len < 1)
		return (FALSE);
	str = del_space(x);
	if (str[0] == '|' || check_syntax_pipe(str))
	{
		syntax_error(str, env);
		return (TRUE);
	}
	else if (!ft_chr_alpha(str) && check_syntax_rr(str))
	{
		syntax_error(str, env);
		return (TRUE);
	}
	else if ((len_order(str, '>') > 2 || len_order(str, '<') > 2) || \
	(check_syntax_ra(str) || check_syntax_rb(str)))
	{
		syntax_error(str, env);
		return (TRUE);
	}
	free_str(str);
	return (FALSE);
}

int	check_pipe_syntax(char *buf, t_env *env, int y)
{
	if (!ft_isalpha(buf[y]))
		if (!in_quotes(buf) && check_syntax(buf, env))
			return (-2);
	return (0);
}

int	check_quote_syntax(char *buf, t_env *env)
{
	int	check;

	env->quote_flag = 0;
	env->x = 0;
	check = count_quotes(buf);
	if (check % 2 != 0)
	{
		ft_putendl_fd("minishell: unclosed quotes: syntax error", \
		STDERR_FILENO);
		free_prompt(env);
		g_error_code = 2;
		return (-2);
	}
	return (0);
}
