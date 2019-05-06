/*
*   TRABALHO FINAL - VIDA ARTIFICIAL NA COMPUTAÇÃO - UFABC - 2019.2
*   AUTOR: NILTON GOMES MARTINS JUNIOR
*   EMAIL: NILTON.JUNIOR@ALUNO.UFABC.EDU.BR
*/

#include "io.h"
#include "cell.h"
#include "automaton.h"
#include "game.h"
#include "rules.h"
#include <string>
#include <cstdlib>
#include <ctime>

// #define MAX_RULES 10 // Número máximo de regras no jogo

// Atende escolha do usuário. 
// Retorna true se o jogo continua após a selecão do usuário e false caso contrário.
bool handleMenuOption(Game &game, const unsigned int option)
{
    bool inloop = true;
    switch (option)
    {
        case 1:
            // Visualizar regras disponíveis
            printRule(game.rule);
            break;
        case 2:
            // Criar nova regra
            game.rule = getNewRule();
            break;
        case 3:
            // Altera o número de iterações
            game.iterations = getIterations();
            break;
        case 4:
            // Visualizar a configuração inicial atual do automato
            printAutomaton(game.state);
            break;
        case 5:
            // Selecionar a configuração inicial do automato
            game.state = getAutomaton();
            break;
        case 6:
            // Iniciar o jogo
            beginGame(game);
            promptEndGame();
            if (getImageOption())
                system("open ./output.ppm");
            break;
        case 7:
            // Terminar o programa
            inloop = false;
            break;
    }

    return inloop;
}

int main()
{
    // Seed aleatória (baseada no relógio)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Inicialização do jogo
    Game game;
    initializeGame(game);

    // Opção do menu selecionada pelo usuário
    unsigned int menuOption;

    // Loop do jogo
    while(true)
    {
        printMenu(game);
        menuOption = getMenuOption();
        bool inloop = handleMenuOption(game, menuOption);
        if (!inloop) break;
    }
    std::cout << "TERMINANDO O PROGRAMA...\n";
    
    return 0;
}
