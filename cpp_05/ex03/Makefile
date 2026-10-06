# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucca <lucca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 19:18:52 by lucca             #+#    #+#              #
#    Updated: 2026/10/06 19:18:53 by lucca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# NAMES
NAME = bureaucrat

# PATHS
SRC_PATH	= src
TESTS_PATH	= $(SRC_PATH)/tests
BUILD_PATH	= build
INC_PATH	= include

# SOURCES
TESTS = $(addprefix $(TESTS_PATH)/, \
	testBureaucrat.cpp \
	testIntern.cpp \
	testPresidentialPardonForm.cpp \
	testRobotomyRequestForm.cpp \
	testShrubberyCreationForm.cpp \
	testUtils.cpp \
)
SRC =  $(addprefix $(SRC_PATH)/, \
	Bureaucrat.cpp \
	Intern.cpp \
	AForm.cpp \
	main.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
)
SRC += $(TESTS)
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

vpath %.cpp $(SRC_PATH) $(TESTS_PATH)

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