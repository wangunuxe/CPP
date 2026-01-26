NAME = EX02

SRCS = A_Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

CXX=c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all