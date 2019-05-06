#ifndef CELL_H
#define CELL_H

#include "automaton.h"
#include "rules.h"

// Define os possíveis estados de uma célula
enum class CellState
{
    DEAD,
    ALIVE
};

// Define a estrutura básica de uma célula
struct Cell
{
    CellState state;
};

// Gera um estado aleatório para a célula
CellState getRandomState();

#endif