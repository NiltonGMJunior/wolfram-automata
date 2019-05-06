#include "io.h"
#include "cell.h"
#include "game.h"
#include <bitset>
#include <limits>
#include <fstream>

void printMenu(Game &game)
{
    std::cout << "------------------------------------\n";
    std::cout << "MENU PRINCIPAL - AUTOMATO DE WOLFRAM\n";
    std::cout << "------------------------------------\n";
    std::cout << "  - OPCOES DISPONIVEIS: \n";
    std::cout << "1 - VISUALIZAR REGRA\n";
    std::cout << "2 - SELECIONAR NOVA REGRA\n";
    std::cout << "3 - ALTERAR NUMERO DE ITERACOES (NUMERO ATUAL: " << game.iterations << ")\n";
    std::cout << "4 - VISUALIZAR CONFIGURACAO INICIAL DO AUTOMATO\n";
    std::cout << "5 - SELECIONAR CONFIGURACAO INICIAL DO AUTOMATO\n";
    std::cout << "6 - INICIAR SIMULACAO\n";
    std::cout << "7 - TERMINAR PROGRAMA\n";
    std::cout << "------------------------------------\n";
    std::cout << "SELECIONE UMA OPÇÃO [1-7]: ";
}

unsigned int getMenuOption()
{
    while (true)
    {
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        unsigned int option;
        std::cin >> option;

        if (std::cin.fail() || option < 1 || option > 7)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ENTRADA INVALIDA! INSIRA UM INTEIRO NO INTERVALO [1-7]\n";
        }
        else
            return option;
    }
}

void printRule(Rule &rule)
{
    std::cout << "| CURRENT STATE | NEXT STATE |\n";
    for (unsigned int iii = 0; iii < 8; ++iii)
        std::cout << "|      " << std::bitset<3>(iii) << "      |" << ((rule.states[iii] == true) ? "   ALIVE    |" : "    DEAD    |") << "\n";
}

Rule getNewRule()
{
    std::cout << "------------------------------------\n";
    std::cout << "DEFINICAO DE NOVA REGRA PARA O AUTOMATO DE WOLFRAM\n";
    std::cout << "------------------------------------\n";
    std::cout << "CONJUNTO DE TRES BITS ABC REPRESENTA UMA VIZINHANCA\n";
    std::cout << "A - CELULA A ESQUERDA\n";
    std::cout << "B - CELULA CENTRAL\n";
    std::cout << "C - CELULA A DIREITA\n";
    std::cout << "CODIFICACAO BINARIA DE ESTADO:\n";
    std::cout << "0 - CELULA ESTA MORTA\n";
    std::cout << "1 - CELULA ESTA VIVA\n";
    std::cout << "PARA CADA UM DOS 8 POSSIVEIS ESTADOS DA VIZINHANCA, DEFINE O PROXIMO ESTADO DA CELULA CENTRAL\n";
    
    Rule new_rule;

    for (unsigned short int iii = 0; iii < 8; ++iii)
    {
        while (true)
        {
            std::cout << "PROXIMO ESTADO PARA CELULA CENTRAL COM VIZINHANCA " << std::bitset<3>(iii) << " [0-1]: ";
            unsigned short int option;
            std::cin >> option;

            if (option == 0 || option == 1)
            {
                new_rule.states[iii] = (option == 0) ? false : true;
                break;
            }
            else
                std::cout << "ENTRADA INVALIDA! INSIRA 0 (DEAD) OU 1 (ALIVE).\n"; 
        }
        std::cout << "\n";
    }
    
    return new_rule;
}

unsigned int getIterations()
{
    while (true)
    {
        std::cout << "DEFINA O NUMERO DE ITERACOES: ";
        unsigned int option;
        std::cin >> option;

        if (std::cin.fail() || option <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ENTRADA INVALIDA! INSIRA UM INTEIRO MAIOR DO QUE 0.\n";
        }
        else
            return option;
    }
}

unsigned int getAutomatonSize()
{
    while (true)
    {
        std::cout << "DEFINA O COMPRIMENTO DO AUTOMATO: ";
        unsigned int option;
        std::cin >> option;

        if (std::cin.fail() || option <= 2)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ENTRADA INVALIDA! INSIRA UM INTEIRO MAIOR DO QUE 2.\n";
        }
        else
            return option;
    }
}

void printAutomaton(Automaton &automaton)
{
    std::cout << "|";
    for (unsigned int iii = 0; iii < automaton.num_cells; ++iii)
        std::cout << (automaton.cells[iii].state == CellState::DEAD ? " |" : "X|");
    std::cout << "\n";
}

Automaton getAutomaton()
{
    Automaton automaton;
    
    automaton.num_cells = getAutomatonSize();
    automaton.cells = new Cell[automaton.num_cells];
    if (automaton.cells == NULL)
    {
        std::cout << "NAO FOI POSSIVEL ALOCAR MEMORIA PARA O AUTOMATO. FINALIZANDO PROGRAMA...\n";
        exit(-1);
    }

    for (unsigned int iii = 0; iii < automaton.num_cells; ++iii)
    {
        while (true)
        {
            std::cout << "DEFINA O ESTADO DA CELULA " << iii + 1 << " [0-1]: ";
            unsigned int option;
            std::cin >> option;
            if (std::cin.fail() || (option != 0 && option != 1))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ENTRADA INVALIDA! INSIRA 0 (DEAD) OU 1 (ALIVE).\n";
            }
            else
            {
                automaton.cells[iii].state = (option == 0 ? CellState::DEAD : CellState::ALIVE);
                break;
            }
        }
    }

    return automaton;
}

bool getImageOption()
{
    while (true)
    {
        std::cout << "DESEJA EXIBIR O RESULTADO DA SIMULACAO [s-S/n-N]? ";
        char option;
        std::cin >> option;

        if (std::cin.fail() || (option != 's' && option != 'S' && option != 'n' && option != 'N'))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ENTRADA INVALIDA!\n";
        }
        else
            return (option == 's' || option == 'S');
    }   
}

void promptEndGame()
{
    std::cout << "SIMULACAO FINALIZADA COM SUCESSO!\n";
}