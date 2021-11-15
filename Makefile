NAME = libftprintf.a

HEADER = ft_printf.h

UTILS_PATH = ./printf_utils/
UTILS = ft_hex_funcs.c ft_putnbr_funcs.c ft_putstr.c

SRCS = ft_printf.c $(addprefix $(UTILS_PATH), $(UTILS))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = $(patsubst %.c, %.o, $(SRCS))

all: ${NAME}

${NAME}: ${OBJ}
		ar rcs ${NAME} ${OBJ} ${HEADER}

%.o : %.c ${HEADER}
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${RM} ${UTILS_PATH}*.o ${UTILS_PATH}*.h.gch
		${RM} *.o *.h.gch

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re