# Compiler settings
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++17

# Target
TARGET = app

# Source files
C_SRC = pokemon.c
CPP_SRC = main.cpp PokemonWrapper.cpp

# Object files
C_OBJ = $(C_SRC:.c=.o)

# Build target
$(TARGET): $(C_OBJ)
	$(CXX) $(CPP_SRC) $(C_OBJ) -o $(TARGET)

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f *.o $(TARGET)