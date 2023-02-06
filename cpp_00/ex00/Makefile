NAME =	megaphone

CC = c++-12

RM = 		@rm -rf


FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

CFILES = megaphone.cpp

OBJECTS = 	$(CFILES:.cpp=.o)

$(NAME): 	$(OBJECTS)
			@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) ./*.o
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY: re fclean clean all
