##
## EPITECH PROJECT, 2023
## Makefile day10
## File description:
## makefile for easier compilation
##

IDIR = ./include
SRCDIR = src
CC = g++
CFLAGS += -g -I$(IDIR) -Wall -Wextra -std=c++23 -O3 -flto
LIBS += -lsfml-graphics -lsfml-window -lsfml-system

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRC = 	main.cpp	\
		$(SRCDIR)/Game.cpp \
		$(SRCDIR)/Map.cpp	\
		$(SRCDIR)/Player.cpp

OBJ = 	$(SRC:.cpp=.o)

NAME = doom

TOTAL_FILES := $(words $(OBJ))
COMPILED_FILES = 0

define show_progress
	$(eval COMPILED_FILES=$(shell echo -e $$(($(COMPILED_FILES)+1))))
	@PERCENT=$$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES))); \
	echo -e "$(COLOUR_BLUE)[$$PERCENT%] \t\t $(COLOUR_GREEN)Compiling $<$(COLOUR_END)"
endef

all:    $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(COLOUR_GREEN)Building...$(COLOUR_END)"
	@$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)
	@echo -e "$(COLOUR_GREEN)Build complete: $(NAME)$(COLOUR_END)"

%.o: %.cpp
	$(call show_progress)
	@$(CC) $(CFLAGS) -c -o $@ $< || (echo -e "$(COLOUR_RED)Compilation error on $<$(COLOUR_END)"; exit 1)

clean:
	@rm -rf $(OBJ)
	@echo -e "$(COLOUR_RED)Removing\t[$(OBJ)]$(COLOUR_END)"

fclean: clean
	@echo -e "$(COLOUR_RED)Removing\t[$(NAME)]$(COLOUR_END)"
	@rm -rf $(NAME)

re:	fclean	all

.PHONY: clean
