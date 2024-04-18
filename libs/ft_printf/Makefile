SRC = ft_print_adress.c \
	  ft_printf_int.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_printf.c \
	  ft_printf_unsigned.c \
	  ft_putnbr_hex.c \
	  ft_strlen.c

SRC_DIR = src

BUILD_DIR = .build

INCLUDE_DIR = include

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -MD -MP

IFLAGS = -I $(INCLUDE_DIR)

NAME = libftprintf.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all