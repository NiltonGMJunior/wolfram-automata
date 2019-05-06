#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include "game.h"

#define CELL_WIDTH 50
#define CELL_HEIGHT 50

std::ofstream getImageFile(Game &game);

void printStateToImage(Game &game, std::ofstream &image);

#endif