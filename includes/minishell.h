/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/08/01 01:14:17 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* perror */
# include <stdio.h>

/* waitpid, wait */
# include <sys/wait.h>

/* open, unlink */
# include <fcntl.h>

/* strerror */
# include <string.h>

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include <signal.h>
# include <unistd.h>
# include <libft.h>

// colors for prompt 
# define MAGENTA "\001\033[0;35m\002"
# define CYAN "\001\033[0;36m\002"
# define RESET "\001\033[0m\002"

# define BUILTIN 6

# define TYPE 1
# define CMD 2
# define OPTION 3
# define ARG 4
# define REDIR 5

# define SAMPLEQ 1
# define DOUBLEQ 0

# define FALSE 0
# define TRUE 1

extern int	g_error_code;

typedef struct s_lst
{
	struct s_token	*token;
	struct s_lst	*next;
}	t_lst;

typedef struct s_token
{
	int				type;
	char			*cmd;
	char			*option;
	char			*arg;
	char			*redir;
}	t_token;

typedef struct s_position
{
	int	start;
	int	end;
	int	flag;
}	t_position;

typedef struct s_var
{
	char			*name;
	char			*content;
	struct s_var	*next;
}	t_var;

typedef struct s_env
{
	t_var	*stack;
	int		length;
	int		pipe_count;
	int		input;
	int		output;
	int		flag_in;
	int		flag_out;
	int		size;
	int		error_code;
	int		delim_size;
	int		flag;
	int		quote_flag;
	int		i;
	int		x;
	int		y;
	char	**envp;
	char	*str;
	char	*new_here;
	char	**new_redir;
	char	*cmd;
	char	*cmd_path;
	char	*home;
	char	*old_pwd;
	char	*user;
	char	*prompt;
	char	*path;
	char	**cmds;
	char	*string;
	char	**paths;
	char	*cmd_envp;
	char	**cmd_exec;
	char	**delimiter;
	char	*magenta;
	char	*cyan;
	char	*middle;
	char	*end;
	char	*reset;
}	t_env;

typedef struct s_datat
{
	char	*opt;
	char	*arg;
}	t_datat;

typedef struct s_sort
{
	char	*cmd;
	char	*redir;
}	t_sort;

t_var		*ft_lstnew_env(char *name, char *content);
t_var		*ft_lstlast_env(t_var *lst);
int			len_c(char *arg, int quote);
int			char_position(char *arg, int c);
void		env_to_stack(t_env *env, char **envp);
void		add_to_stack(t_env *env, char *name, char *content);
void		split_once(t_env *env, char **temp, int x);
void		free_stack(t_var **stack);
void		ft_lstadd_back_env(t_var **lst, t_var *new);
void		free_temp2(char **temp);

t_lst		*lst_new(t_token *data);
t_lst		*lst_last_data(t_lst *lst);
void		lst_add_back(t_lst **lst, t_lst *new);
void		lst_clear(t_lst **lst);

void		ft_init_token(t_token *x);
void		ft_set_token(t_token *token, char *str, int opt);
void		ft_define_type(t_token *token, char	*sort, int i);
void		designate_data_token(t_token *token, char **sort, t_datat *arg_opt);
void		free_token(t_token *token);

int			ft_isredir(char *str);
int			ft_isbuiltin(char *str);

char		*remont_str(char **sort);
char		*ft_merge(char *uni, char *temp);
void		free_temp(char **temp);
void		free_temp_q(char **temp, int size);

int			len_alpha(char *str);
int			end_arg_position(char *str);
char		*split_arg(char *str);
char		*set_expand(char *env_value, char *str);

t_position	set_position_quoter(char *item);
int			get_next_quoter(char *item, int quoter);
int			comp_position(char *item, int len, t_position *x);
int			ft_subspace(char *str, int y);
void		alter_space(char *str, t_position x);

int			in_quotes(const char *str);
int			get_size(char **args);
char		*ft_strdup_limit(const char *s, size_t i);
char		*delete_quoter(char *str);

void		set_single_io(t_env *env, int *in);
void		reset_io(int *input, int *output);
void		set_standard_io(int *input, int *output);

void		verify_execute(t_lst *temp, t_env *env);
void		verify_redirection_io(char *string, t_env *env, int type);
void		check_redir_type(t_env *env, char *redir, int *io);

int			execute_single_builtin(t_lst *temp, t_env *env, char *new);
void		execute_single_command(t_env *env, t_lst *temp);
void		redirection_handle(char *redir, t_env *env, int type, t_lst *temp);

void		get_path(t_env *env);
int			cmd_execve(t_env *env, int input, int output);
int			verify_command(char *cmd, char **paths, t_env *env);
int			check_absolute(char *cmd);

void		ft_cd(t_lst *temp, t_env *env);
int			verify_cd(t_lst *temp, t_env *env);
void		update_pwd(t_var **stack, t_env *env);
void		get_oldpwd(t_var **stack, t_env *env);
void		update_oldpwd(t_var **stack, char *old);
int			locate_cd_arg(int ch, t_lst *temp, t_env *env);

void		ft_env(t_lst *temp, t_env *env, int fd);
void		print_env(t_var *temp, int fd);

int			verify_number(char *arg);
void		ft_exit(t_lst *temp, t_env *env, char *new);
void		free_exit(t_lst *temp, t_env *env, char **args);
void		valid_exit_code(t_lst *temp, t_env *env, char **elem, char *old);
void		exit_valid_error(char **elem, char *new);

int			check_valid_var(char new, int i);
int			check_equal_sign(char *string);
void		export(t_lst *temp, t_env *env, int fd);
void		check_double(char *var, t_var *temp, t_env *env);
void		print_declare(t_var *temp, int fd);
void		add_new_env(int i, int flag, t_env *env, char **arg);
void		export_valid_var(t_lst *temp, t_env *env);

void		pwd(int fd);

void		unset(t_lst *temp, t_env *env);
void		delete_var(char *var, t_var **stack);
void		free_node(t_var *stack);
void		free_n_null(void *ptr);

void		echo(t_lst *temp, int fd);
void		print_echo(char *string, int fd, int size, int i);
void		replace_spaces(char *string);
char		*remove_quotes(char *string);
int			localize_char_position(int i, int x);
void		double_quote_found(t_env *env, int i, char *string);
void		single_quote_found(t_env *env, int i, char *string);
void		in_double_quote_case(t_env *env, char *string, char *new, int i);
void		in_single_quote_case(t_env *env, char *string, char *new, int i);

int			input_redir(char **args, t_env *env);
int			check_infile(char *file);
int			get_size(char **args);

int			redir_error(void);
int			output_redir(char **args);
int			check_outfile(char *file, char *redir);

int			here_doc_prompt(t_env *env, char *string);
int			here_doc_delim_check(char *buf, char *delim, int fd);
void		here_doc_readline(char *string, int fd);
void		here_doc_error(char *string);
void		transfer_all_delimiter(char **elem, t_env *env, int size);
void		join_here_doc(char **args, t_env *env);
void		stop_here_doc(int signal);
void		free_here_docs(int status);

char		*current_path(t_var **stack, t_env *env);
char		*update_prompt(t_env *env);
void		get_user(t_var **stack, t_env *env);
void		get_home(t_var **stack, t_env *env);

void		free_prompt(t_env *env);
void		free_token_lst(t_lst **temp);
void		pipeline_check(t_lst *temp, t_env *env);

void		find_path(t_env *env);
void		join_cmd_arg(t_lst *temp, t_env *env);

char		*get_env(t_var *temp, char *str);
void		initialize(t_env *env);

int			verify_here_redir(char **args);
int			identity_redir(char *string, char *before);
int			count_redir(char *string);
int			only_here_redir(char **args);
char		**transfer_array(char **s1, char **s2);
void		join_new_redir(t_env *env, char **args, int size);
void		get_delimiter(char *string, t_env *env);

int			here_redir_case(char *string, t_env *env, int fd);
int			output_error_check(char **args);
char		**input_error_check(char **args, char **elem, t_env *env);
void		delimiter_error(t_env *env, char **string);
void		readline_handle(int pid, int status, int fd, char *string);

int			identify_quotes(char *string);
void		sig_handler(int signum);
void		log_out(int signum);
void		execve_signal(void);
void		interrupt_here_docs(int signal);
void		quit_process(int signal);
void		interrupt_process(int signal);
void		prompt_signal(void);

void		free_cmd_path(t_env *env);
void		handle_builtin(t_lst *temp, t_env *env, char *arg, int type);
void		handle_cmd(t_lst *temp, t_env *env, char *arg, int type);
void		count_io(t_env *env, char **elem);

void		define_prompt(t_env *env);

int			confirm_command(t_env *env, char *cmd, char **paths);
int			transfer_first(t_lst *temp, t_env *env, char **elem, int x);
void		exec_error(char *cmd, t_env *env);
void		define_exec_error(int exec);
void		transfer_cmd(int count, t_lst *temp, t_env *env, char **elem);

int			error_redir_flag(char **args, int i, int flag);
void		join_all_here(char **args, int i, t_env *env, int flag);

int			set_quoter(int quoter);
int			right_direction(char *string);
int			count_quotes(char *string);
char		*set_string_size(char *string);
void		free_env(t_env *env);

void		free_cmd(t_env *env);
void		cmd_ready_execution(t_env *env, char *string, int i);
void		first_cmd_ready(t_lst *temp, t_env *env);

void		define_cmd_builtin_case(t_token *token);
char		*del_quoter(char *str);

void		prompt_signal(void);
void		put_perror(void);

char		*del_space(char *str);
char		*insert_space(char *str, char c);
char		*ft_del_srq(char *str);
void		aux_reorder(t_sort *x, char **sort, int i);

int			verify_same_char(char *str, char *newstr, char c, t_env *env);
int			verify_diff_char(char *str, char *newstr, char c, t_env *env);
int			verify_next_same_char(char *str, char *newstr, char c, t_env *env);
int			verify_next_diff_char(char *str, char *newstr, char c, t_env *env);

int			check_syntax_pipe(char *x);
void		syntax_error(char *str, t_env *env);

int			check_syntax_rr(char *x);
int			check_syntax_ra(char *x);
int			check_syntax_rb(char *x);
int			check_syntax(char *x, t_env *env);

void		alter_dolar(char *str, int s);
void		alter_char_inquotert(char *str, char c, int s);
void		alter_char_inquoter(char *str, char q, char c, int s);
char		*alter_value(char **tmp, char *uni, int i, t_env *env);
char		*reorder_str(char *str);

char		*ft_expand(t_env *env, char *str);
char		**expand(t_env *env, char *str);
char		*check_variable(t_env *env, char **aux);

int			ft_len_isalphanum(char *str);
int			ft_chr_alpha(char *str);
int			len_order(char *str, char c);
int			ft_len_srq(char *str);
int			get_size_custom(char **args);

void		ft_define_arg(t_token *token, char *arg);
t_token		*put_token_lst(char *str);
void		put_lst(char **sort, t_env *env);

void		get_input(t_env *env);
void		free_main(t_env *env);
void		alter_char_cases(char *buf);
int			check_quote_syntax(char *buf, t_env *env);
int			check_pipe_syntax(char *buf, t_env *env, int y);
int			switch_space_char(char *buf, t_env *env);
void		token_preparation(char *buf, t_env *env);

char		*check_error_code(char *str, char *uni);
int			check_redir_q(char *str);
void		prepare_set_token(char *arg, t_token *token);
void		initialize_counter(t_env *env);
void		free_str(char *str);
void		init_vet(int *x);
void		ft_expand_aux(char *str, t_env *env, char *exp, char **env_value);
void		check_variable_aux(t_env *env, char **aux, char **uni);

#endif