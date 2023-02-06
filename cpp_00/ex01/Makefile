NAME =	My_Awesome_PhoneBook

CC =  c++-12

RM = 		@rm -rf


FLAGS = -g -Wall -Werror -Wextra -fsanitize=address  -std=c++98 -pedantic

CFILES =	awesome_notebook.cpp \
			Contact.cpp \
			PhoneBook.cpp \

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
