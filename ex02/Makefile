CXX			:= c++
CXXFLAGS	:= -Iinclude -Wall -Wextra -Werror
TARGET		:= dreamJob

SRC_PATH	:= src
OBJ_PATH	:= obj

SRC 		:= $(wildcard src/*.cpp)
OBJ 		:= $(SRC:$(SRC_PATH)/%.cpp=$(OBJ_PATH)/%.o)

MAKEFLAGS   += --no-print-directory
RM          := rm -rf

all:	$(TARGET)

$(TARGET):	$(OBJ)
	$(CXX) $(OBJ) -o $@

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
