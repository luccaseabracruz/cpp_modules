# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 14:12:10 by lucca             #+#    #+#              #
#    Updated: 2026/08/13 13:53:21 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAMES
NAME = tests

# PATHS
SRC_PATH	= src
BUILD_PATH	= build
INC_PATH	= include

# SOURCES
SRC =  $(addprefix $(SRC_PATH)/, \
	tests.cpp \
	Account.cpp \
)
OBJ = $(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.cpp=.o)))

# FLAGS
CPP			= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98
CPP_VERSION	= -std=c++98
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
	$(CPP) $(CPP_FLAGS) $(CPP_VERSION) $(INC) $(OBJ) -o $(NAME)

$(BUILD_PATH)/%.o: %.cpp | $(BUILD_PATH)
	$(CPP) $(CPP_FLAGS) $(CPP_VERSION) $(INC) -c $< -o $@

$(BUILD_PATH):
	$(MKDIRP) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all