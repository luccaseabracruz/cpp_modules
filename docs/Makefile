# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 14:12:10 by lucca             #+#    #+#              #
#    Updated: 2026/08/13 17:45:09 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAMES
NAME = executable_name

# PATHS
SRC_PATH	= src
BUILD_PATH	= build
INC_PATH	= include

# SOURCES
SRC =  $(addprefix $(SRC_PATH)/, )
OBJ = $(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.cpp=.o)))

# FLAGS
CPP			= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98
INC			= -I$(INC_PATH)

# COMMANDS
MKDIRP = mkdir -p
RM = rm -f
RMDIR = rm -rf

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

vpath %.cpp $(SRC_PATH)

.PHONY: all clean fclean re

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