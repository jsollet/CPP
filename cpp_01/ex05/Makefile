NAME =	Harl

CC =  c++-12

RM = 		@rm -rf


FLAGS = -g -Wall -Werror -Wextra -fsanitize=address  -std=c++98 -pedantic

CFILES =	main.cpp \
			Harl.cpp

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
