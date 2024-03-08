CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = PmergeMe

SRCS = \
	main.cpp \
	PmergeMe.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $^

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re