CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

DFLAGS = -MD -MP

INCLUDE_DIR = include

EXEC_INCLUDE_DIR = include_exec

PARSING_INCLUDE_DIR = include_parsing

IFLAGS = \
		 -I $(INCLUDE_DIR) \
		 -I $(INCLUDE_DIR)/$(EXEC_INCLUDE_DIR) \
		 -I $(INCLUDE_DIR)/$(PARSING_INCLUDE_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDE_DIR) \

PARSING_SRC = characters.c \
			  fill_cmd.c \
			  fill_operand.c \
			  parsing.c \
			  tree.c \
			  clear.c \
			  fill_file.c \
			  paranthesis.c \
			  expand.c \
			  ft_split_quoted.c \
			  get_name.c \
			  remove_quote.c \
			  wildcard.c \
			  utils.c \
			  remove_quote_heredoc.c 

EXEC_SRC = exec.c \
	  	   exec_cmd.c \
		   free_cmd.c \
		   check_id.c \
	   	   dup_fd.c \
		   close_fds.c \
		   find_root.c \
		   init_env.c \
		   free_env.c \
		   ft_getenv.c \
		   create_env.c \
		   nb_args.c \
		   change_exit_val.c \
		   exec_loop.c \
		   print_sig_cmd.c

SIGNALS_SRC = sig_handler.c \
			  sig_handler_exec.c \
			  check_sig.c \
			  signal_handler.c

FIND_CMD_SRC = check_absolute_path.c \
			   find_command.c \
			   get_cmd_path.c

HEREDOCS_SRC = create_heredoc.c \
			   make_all_heredocs.c \
			   random_name.c \
			   heredocs_write_file.c \
			   del_all_heredocs.c

OPERATOR_SRC = exec_and.c \
	  		   exec_or.c \
	  		   exec_pipe.c

REDIR_SRC = exec_simple_out.c \
	  	    exec_double_out.c \
	  	    exec_double_in.c \
	  	    exec_simple_in.c \
	  	    dup_oldfd.c \
	  	    expand_redirect.c \
	  	    remove_fds_vector.c

PIPES_SRC = create_pipe.c \
			redirect_fd.c \
			exec_node_pipe.c

EXPORT_SRC = check_arg_env.c \
			 display_env.c \
			 export.c \
			 get_env_line.c \
			 inset_env.c

CD_SRC = cd.c \
		 check_args.c \
		 cdpath.c \
		 init_cdpath.c \
		 canonize.c \
		 remove_dot.c \
		 remove_dotdot.c \
		 join_path.c \
		 check_file.c \
		 add_first_slash.c \
		 check_pathmax.c \
		 add_pwd.c \
		 change_env.c \
		 change_dir.c \
		 get_curpath.c

BUILTINS_SRC = $(addprefix export/, $(EXPORT_SRC)) \
			   $(addprefix cd/, $(CD_SRC)) \
			   echo.c \
			   check_builtins.c \
			   pwd.c \
			   exit.c \
			   env.c \
			   unset.c

SRC = $(addprefix src_exec/find_command/, $(FIND_CMD_SRC)) \
	  $(addprefix src_exec/heredocs/, $(HEREDOCS_SRC)) \
	  $(addprefix src_exec/operators/, $(OPERATOR_SRC)) \
	  $(addprefix src_exec/redirections/, $(REDIR_SRC)) \
	  $(addprefix src_exec/pipes/, $(PIPES_SRC)) \
	  $(addprefix src_exec/builtins/, $(BUILTINS_SRC)) \
	  $(addprefix src_exec/signals/, $(SIGNALS_SRC)) \
	  $(addprefix src_parsing/, $(PARSING_SRC)) \
	  $(addprefix src_exec/, $(EXEC_SRC)) \
	  main.c

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

LIBS_DIR = libs

LIBFT_DIR = $(LIBS_DIR)/libft

LIBFT = libft.a

FT_PRINTF_DIR = $(LIBS_DIR)/ft_printf

FT_PRINTF = libftprintf.a

NAME = minishell

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT) -lreadline

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all
