CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET		= megaphone

OBJDIR		= objs
SRCS		= megaphone.cpp
OBJS		= $(OBJDIR)/megaphone.o


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