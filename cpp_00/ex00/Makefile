CPP			= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

NAME = megaphone

.PHONY: all clean fclean re

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all