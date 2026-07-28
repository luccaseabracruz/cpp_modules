CPP			= c++
CPP_FLAGS	= -Wall -Wextra -Werror
CPP_VERSION	= -std=c++98

RM = rm -f

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

NAME = megaphone

.PHONY: all clean fclean re

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(CPP_VERSION) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) $(CPP_VERSION) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all