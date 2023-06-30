
NAME	=	philo
HEADER	=	includes/philo.h

SRC	= 	src
OBJ	= 	obj
SRCS	= 	$(wildcard $(SRC)/*.c)
OBJS	= 	$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
DEPS	= 	$(addsuffix .d, $(basename $(SRCS)))

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MMD

RM	=	-rm -rf

####################################################################
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

