#include "image.h"

std::ofstream getImageFile(Game &game)
{
    std::ofstream image { "output.ppm" };
    image << "P3" << std::endl;
    image << game.state.num_cells * CELL_WIDTH << " " << (game.iterations + 1) * CELL_HEIGHT << std::endl;
    image << "255" << std::endl;

    return image;
}


void printStateToImage(Game &game, std::ofstream &image)
{
    for (unsigned int iii = 0; iii < CELL_HEIGHT; ++iii)
        for (unsigned int jjj = 0; jjj < game.state.num_cells; ++jjj)
            for (unsigned int kkk = 0; kkk < CELL_WIDTH; ++kkk)
                if (game.state.cells[jjj].state == CellState::ALIVE)
                    image << 255 << " " << 255 << " " << 255 << std::endl;
                else
                    image << 0 << " " << 0 << " " << 0 << std::endl;
}   