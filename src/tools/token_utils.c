/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:02:46 by eryoo             #+#    #+#             */
/*   Updated: 2022/08/01 01:34:25 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_token(t_token *x)
{
	x->cmd = NULL;
	x->arg = NULL;
	x->option = NULL;
	x->redir = NULL;
	x->type = 0;
}

char	*del_quoter(char *str)
{
	char	*tmp;
	int		i;
	int		y;
	int		len;

	len = ft_strlen(str);
	tmp = (char *)malloc((len - 1) * sizeof(char));
	i = 0;
	y = 0;
	while (str[i])
	{
		if (i != 0 && i != (len - 1))
			tmp[y++] = str[i];
		i++;
	}
	tmp[y] = '\0';
	return (tmp);
}

void	define_cmd_builtin_case(t_token *token)
{
	if (token->type && token->cmd && !ft_isbuiltin(token->cmd) \
	&& token->type != 5)
		ft_set_token(token, "2", TYPE);
}

void	token_preparation(char *buf, t_env *env)
{
	char	**sort;
	int		y;

	y = 0;
	while (buf[y] == 32 && buf[y + 1])
		y++;
	if (check_quote_syntax(buf, env) == -2)
		return ;
	else if (check_pipe_syntax(buf, env, y) == -2)
		return ;
	else if (switch_space_char(buf, env) == -2)
		return ;
	else
	{
		alter_char_cases(buf);
		sort = expand(&(*env), buf);
		if (get_size_custom(sort))
			put_lst(sort, env);
		else
			free_temp(sort);
	}
	free_prompt(env);
}
