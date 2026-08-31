# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucca <lucca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/27 11:08:36 by lucca             #+#    #+#              #
#    Updated: 2026/08/31 15:36:48 by lucca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAMES
NAME = diamond_trap

# PATHS
BUILD_PATH	= build
INC_PATH	= include
SRC_PATH	= src

# SOURCES
SRC = $(addprefix $(SRC_PATH)/, \
	ClapTrap.cpp \
	DiamondTrap.cpp \
	FlagTrap.cpp \
	main.cpp \
	ScavTrap.cpp \
)

OBJ = $(addprefix $(BUILD_PATH)/,$(notdir $(SRC:.cpp=.o)))

# FLAGS
CPP			= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98
INC			= -I$(INC_PATH)

# COMMANDS
MKDIRP	= mkdir -p
RM		= rm -f
RMDIR	= rm -rf

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re

vpath %.cpp $(SRC_PATH)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(INC) $(OBJ) -o $(NAME)

$(BUILD_PATH)/%.o: %.cpp | $(BUILD_PATH)
	$(CPP) $(CPP_FLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	$(MKDIRP) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all