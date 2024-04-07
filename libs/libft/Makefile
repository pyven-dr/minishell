VECTOR_SRC = new_vector.c \
			 del_vector.c \
			 add_vector.c \
			 get_elem_vector.c

LIST_SRC = ft_lstnew_bonus.c \
	 	   ft_lstadd_front_bonus.c \
	 	   ft_lstsize_bonus.c \
	 	   ft_lstlast_bonus.c \
	 	   ft_lstadd_back_bonus.c \
	 	   ft_lstdelone_bonus.c \
	 	   ft_lstclear_bonus.c \
	 	   ft_lstiter_bonus.c \
	 	   ft_lstmap_bonus.c

MEM_SRC = ft_memset.c \
		  ft_memcpy.c \
		  ft_memmove.c \
	 	  ft_memchr.c \
	 	  ft_memcmp.c \
	 	  ft_calloc.c \
	 	  ft_bzero.c

STR_SRC = ft_atoi.c \
	 	  ft_strchr.c \
	 	  ft_strlcpy.c \
	 	  ft_strlen.c \
	 	  ft_strncmp.c \
	 	  ft_strrchr.c \
	 	  ft_strnstr.c \
	 	  ft_strdup.c \
	 	  ft_substr.c \
	 	  ft_strlcat.c \
	 	  ft_strjoin.c \
	 	  ft_strtrim.c \
	 	  ft_split.c \
	 	  ft_itoa.c \
	 	  ft_strmapi.c \
	 	  ft_striteri.c \
	 	  ft_strcmp.c \
	 	  ft_atoi_base.c \
	 	  ft_strminiminize.c

CHAR_SRC = ft_isalnum.c \
	 	   ft_isalpha.c \
	 	   ft_isascii.c \
	 	   ft_isdigit.c \
	 	   ft_isprint.c \
	 	   ft_tolower.c \
	 	   ft_toupper.c

WRITE_SRC = ft_putchar_fd.c \
	 		ft_putstr_fd.c \
	 		ft_putendl_fd.c \
	 		ft_putnbr_fd.c

SRC = get_next_line.c \
	  $(addprefix vector/, $(VECTOR_SRC)) \
	  $(addprefix list/, $(LIST_SRC)) \
	  $(addprefix memory/, $(MEM_SRC)) \
	  $(addprefix string/, $(STR_SRC)) \
	  $(addprefix characters/, $(CHAR_SRC)) \
	  $(addprefix write/, $(WRITE_SRC))


SRC_DIR = src

BUILD_DIR = .build

INCLUDE_DIR = include

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -MD -MP

IFLAGS = \
		 -I $(INCLUDE_DIR)

NAME = libft.a

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
