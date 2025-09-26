CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = MegaPhone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
