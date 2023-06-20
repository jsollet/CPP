NAME = Dynamic_cast

CC =  c++ #ecole
//CC = g++ #maison

RM = 		@rm -rf


FLAGS = -g -Wall -Werror -Wextra -std=c++98 -pedantic # -fsanitize=address

CFILES =	main.cpp \
			Base.cpp \
			A.cpp \
			B.cpp \
			C.cpp \
			

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
