#pragma once
#include <string>

extern "C" {
    #include "pokemon.h"

    int runGame();
}

class PokemonWrapper 
{
    public:
        //default constructor
        PokemonWrapper();
        //default destructor
        ~PokemonWrapper();
        void run();
};