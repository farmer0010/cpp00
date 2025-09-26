CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS = Main.cpp Contact.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
