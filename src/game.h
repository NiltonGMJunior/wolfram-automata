#ifndef GAME_H
#define GAME_H

#include "automaton.h"
#include "rules.h"
#include <string>

#define MAX_RULES 1

// Define a estrtura de um jogo
struct Game
{
    unsigned int iterations;            // Número de iterações
    Automaton state;                    // Autômato que dá o estado atual do jogo
    Rule rule;                        // Conjunto de regras disponíveis
};

// Inicializa o jogo com valores padrão
void initializeGame(Game &game);

// Roda o jogo
void beginGame(Game &game);

// Define o estado inicial com base numa string de 0s e 1s
void setInitialState(Game &game, std::string initial_state);

#endif