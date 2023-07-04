
NAME	=	philo
HEADER	=	includes/philo.h

SRC		= 	src
OBJ		= 	obj
SRCS	= 	$(wildcard $(SRC)/*.c)
OBJS	= 	$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
DEPS	= 	$(addsuffix .d, $(basename $(SRCS)))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MMD -g

RM		=	-rm -rf

####################################################################
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $@

linux: $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -pthread -I $(HEADER) $(OBJS) -o $(NAME)

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


