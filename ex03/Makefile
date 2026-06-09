# -*- Makefile -*-

PROG=clap
CC=c++
FLAGS=-Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
CPP=main.cpp\
	ClapTrap.cpp\
	ScavTrap.cpp\
	FragTrap.cpp\
	DiamondTrap.cpp
OPP=$(CPP:.cpp=.o)

all: $(PROG)

$(PROG): $(OPP)
	$(CC) $(FLAGS) $(OPP) -o $@ -g

%.o:%.cpp
	$(CC) $(FLAGS) $< -c -o $@ -g

clean:
	rm -rf $(OPP)

fclean: clean
	rm -rf $(PROG)

re: fclean all

.PHONY: all clean fclean re
