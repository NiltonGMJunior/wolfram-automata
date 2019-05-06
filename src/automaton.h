#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "cell.h"
#include "rules.h"

// Define a estrutura básica de um automato de Wolfram como um array de células
struct Automaton
{
    unsigned int num_cells; // Número de células no automato
    struct Cell *cells; // Conjunto de células
};

// Atualiza o automato, de acordo com uma determinada regra
Automaton updateAutomaton(Automaton &automaton, struct Rule &rule);

// Gera um ponteiro para um automato inicializado aleatoriamente com um número de células arbitrário
Automaton getRandomAutomaton(const unsigned int num_cells);

#endif