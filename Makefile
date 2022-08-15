NAME = bin/Picross

SRCS = src/Brck.cpp src/Brck.h src/main.cpp src/Picross.cpp src/Picross.h src/Pixel.cpp src/Pixel.h src/Table.cpp src/Table.h

HEADER = src/Picross.h

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRCS))

C=g++
FLAGS = -g -Wall

.PHONY : all clean fclean re folders

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(C) $(FLAGS) $? -o $(NAME)
# ar rcs $(NAME) $?

obj/%.o : src/%.cpp $(HEADER) folders
	$(C) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

folders : obj bin

obj :
	mkdir obj

bin :
	mkdir bin
