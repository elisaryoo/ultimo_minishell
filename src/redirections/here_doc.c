/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:30:48 by eryoo             #+#    #+#             */
/*   Updated: 2022/07/26 19:47:10 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_delimiter(char *string, t_env *env)
{
	int		size;
	char	**elem;

	elem = ft_split(string, ' ');
	size = get_size(elem);
	env->delimiter = (char **)ft_calloc(size + 1, sizeof(char *));
	transfer_all_delimiter(elem, env, size);
	free_temp(elem);
}

int	here_doc_prompt(t_env *env, char *string)
{
	int		fd;
	int		pid;
	int		status;
	int		size;

	size = get_size(env->delimiter);
	fd = open("/tmp/heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	close(fd);
	signal(SIGINT, SIG_IGN);
	status = 0;
	pid = fork();
	readline_handle(pid, status, fd, string);
	if (env->delim_size < size && g_error_code != 130)
	{
		env->delim_size++;
		if (env->delimiter[env->delim_size] != NULL)
			here_doc_prompt(env, env->delimiter[env->delim_size]);
	}
	fd = open("/tmp/heredoc", O_RDONLY);
	return (fd);
}

void	readline_handle(int pid, int status, int fd, char *string)
{
	if (pid == 0)
		here_doc_readline(string, fd);
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status))
			g_error_code = 130;
	}
}

void	here_doc_readline(char *string, int fd)
{
	char	*buf;

	signal(SIGINT, stop_here_doc);
	while (1)
	{
		buf = readline("> ");
		if (buf == NULL)
		{
			here_doc_error(string);
			free_here_docs(0);
		}
		if (here_doc_delim_check(buf, string, fd))
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	free_here_docs(0);
}

int	here_doc_delim_check(char *buf, char *delim, int fd)
{
	int	size;
	int	flag;

	flag = 0;
	if (ft_strlen(buf) > ft_strlen(delim))
		size = (int)ft_strlen(buf);
	else
		size = (int)ft_strlen(delim);
	fd = open("/tmp/heredoc", O_WRONLY | O_APPEND);
	if (!ft_strncmp(buf, delim, size))
	{
		close(fd);
		flag++;
	}
	else
	{
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		close(fd);
	}
	if (flag >= 1)
		return (1);
	else
		return (0);
}
