CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = Bureaucrat

SRCS = \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	main.cpp \

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
	$(RM) *_shrubbery

re :
	make fclean
	make all

.PHONY : all clean fclean re