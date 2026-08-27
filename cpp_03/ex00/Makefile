# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucca <lucca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/27 11:08:36 by lucca             #+#    #+#              #
#    Updated: 2026/08/27 14:36:02 by lucca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAMES
NAME = clap_trap

# PATHS
BUILD_PATH	= build

# SOURCES
SRC = \
	main.cpp \
	ClapTrap.cpp

OBJ = $(addprefix $(BUILD_PATH)/,$(SRC:.cpp=.o))

# FLAGS
CPP			= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

# COMMANDS
MKDIRP	= mkdir -p
RM		= rm -f
RMDIR	= rm -rf

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

$(BUILD_PATH)/%.o: %.cpp | $(BUILD_PATH)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIRP) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all