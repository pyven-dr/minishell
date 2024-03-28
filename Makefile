CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DFLAGS = -MD -MP

INCLUDE_DIR = include

IFLAGS = \
		 -I $(INCLUDE_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDE_DIR)

SRC = exec.c \
	  exec_cmd.c \
	  free_cmd.c \
	  find_command.c \
	  get_cmd_path.c \
	  check_absolute_path.c \
	  exec_and.c \
	  exec_or.c \
	  check_id.c \
	  exec_pipe.c \
	  exec_simple_in.c \
	  dup_fd.c \
	  exec_simple_out.c \
	  exec_double_out.c \
	  random_name.c \

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
	mkdir -p .build
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
