CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

DFLAGS = -MD -MP

INCLUDE_DIR = include

IFLAGS = \
		 -I $(INCLUDE_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDE_DIR)

FIND_CMD_SRC = check_absolute_path.c \
			   find_command.c \
			   get_cmd_path.c

HEREDOCS_SRC = create_heredoc.c \
			   make_all_heredocs.c \
			   random_name.c

OPERATOR_SRC = exec_and.c \
	  		   exec_or.c \
	  		   exec_pipe.c

REDIR_SRC = exec_simple_out.c \
	  	    exec_double_out.c \
	  	    exec_double_in.c \
	  	    exec_simple_in.c \
	  	    dup_oldfd.c

PIPES_SRC = create_pipe.c \
			redirect_fd.c \
			exec_node_pipe.c

BUILTINS_SRC = echo.c \
			   check_builtins.c \


SRC = $(addprefix find_command/, $(FIND_CMD_SRC)) \
	  $(addprefix heredocs/, $(HEREDOCS_SRC)) \
	  $(addprefix operators/, $(OPERATOR_SRC)) \
	  $(addprefix redirections/, $(REDIR_SRC)) \
	  $(addprefix pipes/, $(PIPES_SRC)) \
	  $(addprefix builtins/, $(BUILTINS_SRC)) \
	  exec.c \
	  exec_cmd.c \
	  free_cmd.c \
	  check_id.c \
	  dup_fd.c \
	  close_fds.c \
	  free_tree.c \
	  find_root.c \

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src_exec

LIBS_DIR = libs

LIBFT_DIR = $(LIBS_DIR)/libft

LIBFT = libft.a

NAME = minishell

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) -g -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT)

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
