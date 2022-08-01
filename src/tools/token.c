/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:34:18 by dramos-p          #+#    #+#             */
/*   Updated: 2022/07/31 17:53:37 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_set_token(t_token *token, char *str, int opt)
{
	if (opt == CMD)
	{
		if (in_quotes(str))
			token->cmd = del_quoter(str);
		else
			token->cmd = ft_strdup(str);
	}
	if (opt == ARG)
		token->arg = ft_strdup(str);
	if (opt == OPTION)
		token->option = ft_strdup(str);
	if (opt == REDIR)
		token->redir = ft_strdup(str);
	if (opt == TYPE)
	{
		if (ft_strncmp(str, "2", 1) == 0)
			token->type = CMD;
		if (ft_strncmp(str, "6", 1) == 0)
			token->type = BUILTIN;
		if (ft_strncmp(str, "5", 1) == 0)
			token->type = REDIR;
	}
}

void	free_token(t_token *token)
{
	if (token->arg)
		free(token->arg);
	if (token->cmd)
		free(token->cmd);
	if (token->option)
		free(token->option);
	if (token->redir)
		free(token->redir);
	if (token)
		free(token);
}

void	ft_define_type(t_token *token, char *sort, int i)
{
	if (ft_isredir(sort) && !in_quotes(sort))
		ft_set_token(token, "5", TYPE);
	else if (i == 0 && sort)
	{
		if (ft_isbuiltin(sort))
			ft_set_token(token, "6", TYPE);
		else
			ft_set_token(token, "2", TYPE);
		ft_set_token(token, sort, CMD);
	}
	else if (ft_isbuiltin(sort))
		ft_set_token(token, "6", TYPE);
}

void	designate_data_token(t_token *token, char **sort, t_datat *arg_opt)
{
	int		i;
	int		len;

	i = 0;
	len = get_size(sort) - 1;
	while (sort[i])
	{
		ft_define_type(token, sort[i], i);
		define_cmd_builtin_case(token);
		if (i > 0 && sort[i][0] == '-')
			arg_opt->opt = ft_merge(arg_opt->opt, &sort[i][1]);
		else if (sort[i][0] == '<' || sort[i][0] == '>')
		{
			arg_opt->arg = ft_merge(arg_opt->arg, sort[i]);
			if (len > i)
				arg_opt->arg = ft_merge(arg_opt->arg, " ");
		}
		else if (i > 0 && sort[i][0] != '-')
		{
			arg_opt->arg = ft_merge(arg_opt->arg, sort[i]);
			if (len > i)
				arg_opt->arg = ft_merge(arg_opt->arg, " ");
		}
		i++;
	}
}
