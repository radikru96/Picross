NAME = bin/Picross

SRCS = src/Brick.cpp src/main.cpp src/Picross.cpp src/Field.cpp src/Data.cpp src/Pixel.cpp src/BrickField.cpp src/DataField.cpp

HEADER = src/Brick.h src/Picross.h src/Field.h src/Data.h src/Pixel.h src/DataStack.h src/BrickField.h src/DataField.h

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRCS))

C=g++
FLAGS = -std=c++17 -g -Wall

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
