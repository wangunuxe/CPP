NAME = phonebook
#file = srcs + objs
SRCS = main.cpp \
	Phonebook.cpp \
	Contact.cpp
OBJS = $(SRCS:.cpp=.o)
# compiler + flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
#rules
all: $(NAME)
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
