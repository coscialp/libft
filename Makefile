# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 18:12:55 by coscialp          #+#    #+#              #
#    Updated: 2021/03/09 10:27:58 by akerdeka         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;38;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m

SSRC =		$(addprefix str/, ft_putchar.c ft_putchar_fd.c\
			ft_putendl.c ft_putendl_fd.c ft_strncmp.c\
			ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strcmp.c\
			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c\
			ft_strfjoin.c ft_strlen.c ft_strstr.c ft_substr.c\
			ft_split.c get_next_line.c\
			ft_strncpy.c ft_strchr.c ft_strndup.c\
			ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strtrim.c\
			ft_strnlen.c ft_strrchr.c ft_strnstr.c ft_free_tab.c ft_putstr_tab.c\
			ft_split_line.c ft_strwcdup.c ft_stris.c ft_strrev.c ft_whilestris.c\
			ft_strtok.c)

CSRC =		$(addprefix char/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isspace.c ft_isprint.c\
			ft_islower.c ft_isupper.c ft_isdigit.c ft_is_number.c)

ISRC =		$(addprefix math/, ft_atoi.c ft_putnbr_fd.c ft_putnbr_base.c ft_itoa.c ft_itoa_base.c ft_itoa_ll_base.c\
			ft_itoa_u_base.c ft_ftoa.c st_limit.c)

MSRC =		$(addprefix mem/, ft_memset.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_calloc.c ft_bzero.c ft_memdel.c ft_realloc.c ft_memalloc.c ft_xmalloc.c)

LSRC =		$(addprefix lst/, ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_lstiter.c\
			ft_lstlast.c ft_lstnew.c ft_lstsize.c)

HSRC =		$(addprefix hash/, ft_hashnew.c ft_hashadd_front.c\
			ft_hashadd_back.c ft_hashdel.c ft_hash_display.c ft_hash_free.c\
			ft_hash_search_value.c ft_hashlen.c ft_hash_change_value.c\
			ft_hash_init.c ft_hash_sort.c ft_hash_find.c)

PSRC =		$(addprefix ft_printf/, ft_printf.c handler_convert.c handler_convert_int.c\
			ft_is.c ft_analyser.c ft_set_flags.c ft_set_width.c ft_apply_flags.c\
			ft_apply_convert.c ft_strjoin_zero.c ft_itoa_pf.c ft_dprintf.c)

STSRC =		$(addprefix stack/, new_stack.c stack_pop.c stack_size.c stack_push.c)

FLAG =		-Wall -Werror -Wextra -O3 -g3 #-fsanitize=address#-fsanitize=undefined 

SRCS_NAME	=	$(SSRC) $(CSRC) $(ISRC) $(MSRC) $(SRCS_FREE) $(LSRC) $(PSRC) $(HSRC) $(STSRC)

HEADER		=	includes/

SRC_PATH	=	src/

SRCS		=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

OBJ_NAME	=	${SRCS_NAME:.c=.o}

OBJ_PATH	=	bin/

OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME		=	libft.a

CC			=	cc

RM			=	rm -rf

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ)
	@printf "	\033[2K\r\033[1;38;5;110mlibft\t\t: \033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/char 2> /dev/null
	@mkdir -p bin/ft_printf 2> /dev/null
	@mkdir -p bin/lst 2> /dev/null
	@mkdir -p bin/mem 2> /dev/null
	@mkdir -p bin/math 2> /dev/null
	@mkdir -p bin/str 2> /dev/null
	@mkdir -p bin/hash 2> /dev/null
	@mkdir -p bin/stack 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@printf "\33[2K\r$(ORANGE)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -g3 -I ${HEADER} -c $< -o $@

pull:
	@git pull origin master

norme:
	@norminettev2 $(SRC_PATH) $(HEADER)

clean:
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting libft srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH}
	@printf "\33[2K\r$(ORANGE)Deleted successfully!\n\033[0m"

fclean: clean
	@${RM} ${NAME}

re: fclean pull all
