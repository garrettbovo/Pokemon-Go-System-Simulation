#include "PokemonWrapper.hpp"

/*HOW TO COMPILE AND RUN PROGRAM
cd pokemon-cpp
gcc -c pokemon.c
g++ main.cpp PokemonWrapper.cpp pokemon.o -o app
./app

USING MAKEFILE
make clean
make
./app
*/

int main() 
{
    PokemonWrapper game;
    
    game.run();

    return 0;
}