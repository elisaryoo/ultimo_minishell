# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 23:03:51 by dramos-p          #+#    #+#              #
#    Updated: 2022/08/01 01:39:01 by dramos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LIB_REDLINE	=	-L/usr/include -lreadline
INCLUDE		=	-Iincludes
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft 
LIB			=	-L ./libft -lft
OBJ			=	$(patsubst src%, obj%, $(PATHS:.c=.o))

SRC_FILES	=	minishell.c\

ENV_STACK_FILES =	env_utils.c\
					envp_to_env.c\

TOOLS_FILES =	lst.c\
				token.c\
				check.c\
				free.c\
				util.c\
				space.c\
				libft_custom.c\
				token_utils.c\

REDIRECTIONS_FILES =	input.c\
						output.c\
						here_doc.c\
						redir_utils.c\
						here_error_signals.c\
						input_utils.c\
						here_doc_utils.c\

EXECUTION_SYSTEM_FILES = 	execute.c\
							prompt.c\
							fd_io.c\
							single_cmd.c\
							single_builtin.c\
							execute_utils.c\
							cmd_error_signals.c\
							cmd_path.c\

BUILTINS_FILES 	=	cd.c\
					pwd.c\
					env.c\
					unset.c\
					export.c\
					exit.c\
					echo.c\
					syntax_utils.c\
					exit_utils.c\
					quotes_utils.c\
					export_utils.c\

SRC_TOKENIZER	= 		expand.c\
						expand_util.c\
						initialize.c\
						space_case.c\
						redir_case.c\
						pipe_case.c\
						token_type.c\
						alter_char_case.c\
						get_size_case.c\
						syntax_error_case.c\
						free_utils.c\
						space_case_utils.c\
						alter_char_utils.c\
						util.c\


ENV_STACK_PATH = $(addprefix src/env_stack/, $(ENV_STACK_FILES))
SRC_PATH = $(addprefix src/, $(SRC_FILES))
TOOLS_PATH = $(addprefix src/tools/, $(TOOLS_FILES))
REDIRECTIONS_PATH = $(addprefix src/redirections/, $(REDIRECTIONS_FILES))
EXECUTION_SYSTEM_PATH = $(addprefix src/execution_system/, $(EXECUTION_SYSTEM_FILES))
BUILTINS_PATH = $(addprefix src/builtins/, $(BUILTINS_FILES))
TOKENIZER_PATH = $(addprefix src/tokenizer/, $(SRC_TOKENIZER))
PATHS = $(SRC_PATH) $(TOKENIZER_PATH) $(ENV_STACK_PATH) $(TOOLS_PATH) \
		$(REDIRECTIONS_PATH) $(EXECUTION_SYSTEM_PATH) $(BUILTINS_PATH)

OBJS_DIR	=	obj\
				obj/tokenizer\
				obj/env_stack\
				obj/tools\
				obj/redirections\
				obj/execution_system\
				obj/builtins\

all:		$(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(INCLUDE) -o $@ $^ $(LIB) $(LIB_REDLINE)

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@make -s bonus -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p $(OBJS_DIR)

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) $(INCLUDE) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJS_DIR) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re