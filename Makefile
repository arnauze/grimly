OBJECTS = *.o
BINAIRE = grimly
SRC = libft/*.c\
		src/main.c\
		src/variables.c\
		src/queue.c\
		src/map.c\
		src/algorithm.c\
		src/helper_functions.c\
		src/helper_functions2.c\

FLAGS = -Wall -Wextra -Werror 
NAME = grimly.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I header/grimly.h
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	gcc $(FLAGS) src/main.c -o $(BINAIRE) $(NAME)

sanitize:
	clang -fsanitize=address -fno-omit-frame-pointer -g src/main.c -o $(BINAIRE) $(NAME)

lldb:
	gcc -g $(SRC) $(NAME)

cleanlldb:
	rm a.out
	rm -r a.out.dSYM

runlldb:
	lldb ./a.out

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(BINAIRE)
	rm -f $(NAME)

re: fclean all
