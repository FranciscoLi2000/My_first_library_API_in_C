# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mylib <mylib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 00:00:00 by mylib             #+#    #+#              #
#    Updated: 2025/11/25 00:00:00 by mylib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDE_DIR = include
SRC_DIR = src

LIBFT_DIR = $(SRC_DIR)/libft
GNL_DIR = $(SRC_DIR)/get_next_line
PRINTF_DIR = $(SRC_DIR)/ft_printf

# Libft source files (Part 1 & Part 2)
LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
             ft_isprint.c ft_strlen.c ft_toupper.c ft_tolower.c \
             ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
             ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
             ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
             ft_atoi.c ft_calloc.c ft_strdup.c \
             ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
             ft_itoa.c ft_strmapi.c ft_striteri.c \
             ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Libft bonus source files (linked list functions)
LIBFT_BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
                   ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
                   ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Get Next Line source files
GNL_SRCS = get_next_line.c get_next_line_utils.c

# ft_printf source files
PRINTF_SRCS = ft_printf.c ft_printf_utils.c ft_printf_conversions.c

LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS:.c=.o))
LIBFT_BONUS_OBJS = $(addprefix $(LIBFT_DIR)/, $(LIBFT_BONUS_SRCS:.c=.o))
GNL_OBJS = $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o))
PRINTF_OBJS = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS:.c=.o))

ALL_OBJS = $(LIBFT_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
ALL_BONUS_OBJS = $(LIBFT_OBJS) $(LIBFT_BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# Colors for output
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(ALL_OBJS)
	@$(AR) $(NAME) $(ALL_OBJS)
	@echo "$(GREEN)✓ Library $(NAME) created successfully$(NC)"

bonus: $(ALL_BONUS_OBJS)
	@$(AR) $(NAME) $(ALL_BONUS_OBJS)
	@echo "$(GREEN)✓ Library $(NAME) created with bonus$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "$(BLUE)Compiled: $<$(NC)"

clean:
	@$(RM) $(ALL_OBJS) $(LIBFT_BONUS_OBJS)
	@echo "$(RED)✗ Object files removed$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✗ Library $(NAME) removed$(NC)"

re: fclean all

test: test_libft test_gnl test_printf test_lst

test_libft: $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) tests/test_libft.c $(NAME) -o test_libft
	@echo "$(GREEN)✓ test_libft compiled$(NC)"
	@./test_libft

test_gnl: $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -D BUFFER_SIZE=42 tests/test_gnl.c $(NAME) -o test_gnl
	@echo "$(GREEN)✓ test_gnl compiled$(NC)"
	@./test_gnl

test_printf: $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) tests/test_printf.c $(NAME) -o test_printf
	@echo "$(GREEN)✓ test_printf compiled$(NC)"
	@./test_printf

demo: $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) examples/demo.c $(NAME) -o demo
	@echo "$(GREEN)✓ demo compiled$(NC)"
	@./demo

test_lst_only: bonus
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) tests/test_lst.c $(NAME) -o test_lst
	@echo "$(GREEN)✓ test_lst compiled$(NC)"

clean_tests:
	@$(RM) test_libft test_gnl test_printf test_lst demo
	@echo "$(RED)✗ Test binaries removed$(NC)"

.PHONY: all bonus clean fclean re test test_libft test_gnl test_printf test_lst demo clean_tests

test_lst: bonus
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) tests/test_lst.c $(NAME) -o test_lst
	@echo "$(GREEN)✓ test_lst compiled$(NC)"
	@./test_lst
