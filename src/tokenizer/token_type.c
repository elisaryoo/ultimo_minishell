/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:45:50 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/31 21:30:53 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_define_arg(t_token *token, char *arg)
{
	if (arg)
	{
		if (ft_isredir(arg) && !in_quotes(arg))
			prepare_set_token(arg, token);
		else if (ft_isredir(arg) && check_redir_q(arg))
			prepare_set_token(arg, token);
		else
			ft_set_token(token, arg, ARG);
		free(arg);
	}
}

void	prepare_set_token(char *arg, t_token *token)
{
	int		i;
	char	*tmp;

	tmp = split_arg(&(*arg));
	i = ft_strlen(tmp);
	ft_set_token(token, tmp, ARG);
	ft_set_token(token, &arg[i], REDIR);
	if (tmp)
		free(tmp);
}

t_token	*put_token_lst(char *str)
{
	char	**sort;
	t_datat	*arg_opt;
	t_token	*token;

	sort = ft_split(str, ' ');
	arg_opt = (t_datat *)malloc(sizeof(t_datat));
	arg_opt->arg = NULL;
	arg_opt->opt = NULL;
	arg_opt->opt = ft_merge(arg_opt->opt, "-");
	token = (t_token *)malloc(sizeof(t_token));
	ft_init_token(token);
	designate_data_token(token, sort, arg_opt);
	ft_define_arg(token, arg_opt->arg);
	if (arg_opt->opt)
	{
		if (ft_strlen(arg_opt->opt) > 1)
			ft_set_token(token, arg_opt->opt, OPTION);
		free(arg_opt->opt);
	}
	if (sort)
		free_temp(sort);
	free(arg_opt);
	return (token);
}

void	put_lst(char **sort, t_env *env)
{
	t_token	*token;
	t_lst	*cmd_lst;
	char	*tmp;
	int		i;

	i = 0;
	env->string = remont_str(sort);
	env->cmds = ft_split(env->string, '|');
	while (env->cmds[i])
	{
		tmp = reorder_str(env->cmds[i]);
		token = put_token_lst(tmp);
		if (i == 0)
			cmd_lst = lst_new(token);
		else
			lst_add_back(&cmd_lst, lst_new(token));
		free_token(token);
		if (tmp != NULL)
			free(tmp);
		i++;
	}
	verify_execute(cmd_lst, env);
	free_temp(env->cmds);
	free(env->string);
	lst_clear(&cmd_lst);
}
