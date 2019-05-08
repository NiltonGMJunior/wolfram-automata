#include "game.h"
#include "io.h"
#include "automaton.h"
#include "image.h"

void initializeGame(Game &game)
{
    game.iterations = 10;                   // Número de iterações padrão
    game.rule = getRandomRule();            // Cria uma regra aleatória
    game.state = getRandomAutomaton(10);    // Inicia o jogo com um automato aleatorio de     
}

void beginGame(Game &game)
{
    std::ofstream image = getImageFile(game);
    for (unsigned int iii = 0; iii < game.iterations + 1; ++iii)
    {
        printAutomaton(game.state);
        printStateToImage(game, image);        
        game.state = updateAutomaton(game.state, game.rule);
    }
}