NAME = concat
CC = gcc
SRC = $(wildcard src/*.c)
DEPS = $(wildcard include/*.h)
INC_DIR = include/
TARGET = $(NAME)

FLAGS = -Wall -Wextra -O2 -std=gnu11 -I $(INC_DIR)

prog:
	$(CC) $(FLAGS) $(SRC) -o $(TARGET)
