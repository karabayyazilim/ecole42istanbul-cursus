NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)


re:	fclean $(NAME)

