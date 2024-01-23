NAME = mute

FUNC = main.cpp

OBJS = ${FUNC:.cpp=.o}

CC = g++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -rf

.PHONY: all clean fclean re bonus

all: ${NAME}

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
			rm -rf ${NAME}
			rm -rf ${OBJS}
			
fclean :	clean
			
re	:	fclean all clean
