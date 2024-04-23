CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
TARGET		= phonebook

OBJDIR		= objs
SRCS 		= $(shell find . -name '*.cpp')
OBJS 		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJDIR)/%.o:	%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(TARGET)

.PHONY: all clean fclean