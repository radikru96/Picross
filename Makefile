NAME = bin/Picross

SRCS = src/Brck.cpp src/main.cpp src/Picross.cpp src/Pixel.cpp src/Table.cpp

HEADER = src/Brck.h src/Picross.h src/Pixel.h src/Table.h

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
