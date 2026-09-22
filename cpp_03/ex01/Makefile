# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/27 11:08:36 by lucca             #+#    #+#              #
#    Updated: 2026/09/22 15:11:46 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAMES
NAME = scav_trap

# PATHS
BUILD_PATH	= build
INC_PATH	= include
SRC_PATH	= src
TESTS_PATH	= $(SRC_PATH)/tests

# SOURCES
TESTS = $(addprefix $(TESTS_PATH)/, \
	testClapTrap.cpp \
	testScavTrap.cpp \
)

SRC = $(addprefix $(SRC_PATH)/, \
	ClapTrap.cpp \
	main.cpp \
	ScavTrap.cpp \
)
SRC += $(TESTS)

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

vpath %.cpp $(SRC_PATH) $(TESTS_PATH)

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