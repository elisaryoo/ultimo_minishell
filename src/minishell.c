/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:26:28 by dramos-p          #+#    #+#             */
/*   Updated: 2022/08/01 01:34:14 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_error_code;

static void	check_error_code_aux(char *str, char **uni, char **x)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strlen(str))
		tmp = ft_strdup(str);
	free (*x);
	*x = ft_itoa(g_error_code);
	*uni = ft_merge(*uni, *x);
	*uni = ft_merge(*uni, tmp);
	if (tmp)
		free(tmp);
}

char	*check_error_code(char *str, char *uni)
{
	char	*tmp;

	tmp = NULL;
	if (str[1] && str[1] == '"')
	{
		free (str);
		str = ft_itoa(g_error_code);
		uni = ft_merge(uni, str);
		uni = ft_merge(uni, "\"");
	}
	else if (str[0] && str[0] == '?')
	{
		if (str[1])
			tmp = ft_strdup(&str[1]);
		free (str);
		str = ft_itoa(g_error_code);
		uni = ft_merge(uni, str);
		if (tmp)
			uni = ft_merge(uni, tmp);
		free_str(tmp);
	}
	else
		check_error_code_aux(&str[1], &uni, &str);
	free(str);
	return (uni);
}

int	check_redir_q(char *str)
{
	int		flag;
	int		i;

	flag = FALSE;
	i = 0;
	while (str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			flag = TRUE;
		if ((str[i] == 34 || str[i] == 39) && flag == FALSE)
			return (1);
		i++;
	}
	return (0);
}

void	get_input(t_env *env)
{
	char	*buf;
	char	*prompt;

	while (1)
	{
		prompt = update_prompt(env);
		prompt_signal();
		buf = readline(prompt);
		if (buf == NULL)
			break ;
		add_history(buf);
		token_preparation(buf, env);
		if (buf)
			free(buf);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	env;

	(void)argc;
	(void)argv;
	env.envp = envp;
	g_error_code = 0;
	env_to_stack(&env, envp);
	initialize(&env);
	get_home(&(env.stack), &env);
	get_user(&(env.stack), &env);
	get_input(&env);
	free_main(&env);
	ft_putendl_fd("exit", 1);
	exit(g_error_code);
	return (0);
}
