#include "cell.h"

CellState getRandomState()
{
    return (std::rand() % 2 == 0) ? CellState::DEAD : CellState::ALIVE;
}