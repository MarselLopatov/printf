NAME = libftprintf.a
LIB = libft.a

CFLAGS = -Wall -Wextra -Werror

HEADERS = $(PATH_LIB)libft.h printf.h

PATH_LIB = ./libft/
LIB_SRCS = ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c

SRCS = ft_printf.c ft_printf_utils.c

CC = gcc

RM = rm -f

OBJ = $(addprefix ${PATH_LIB}, $(LIB_SRCS)) $(patsubst %.c, %.o, $(SRCS))

all: run_lib ${NAME}

run_lib:
		@make -C ${PATH_LIB}

${NAME}: ${OBJ}
		ar rcs ${NAME} ${OBJ} ${HEADERS}

%.o : %.c ${HEADERS}
		${CC} ${CFLAGS} -c $< -o $@

clean:
		@make -C ${PATH_LIB}
		${RM} *.o *.h.gch

fclean: clean
		@make -C ${PATH_LIB} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re