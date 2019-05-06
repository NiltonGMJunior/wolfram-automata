#ifndef IO_H
#define IO_H

#include <iostream>
#include "game.h"
#include "rules.h"
#include "automaton.h"
#include <string>

// Imprime o menu inicial
void printMenu(Game &game);

// Lê a opção escolhida do menu inicial
unsigned int getMenuOption();

// Imprime a lista de regras
void printRulesList(Game &game);

// Lê a opção escolhida do menu de regras

// Imprime uma regra
void printRule(Rule &rule);

// Define qual o índice da regra ativa
unsigned int getActiveRule(Game &game);

// Lẽ o número de iterações à serem executadas
unsigned int getIterations();

// Lê o número de células no automato
unsigned int getAutomatonSize();

// Lê uma nova regra, definida pelo usuário
Rule getNewRule();

// Lê o nome da nova regra
std::string getRuleName();

// Lê os parâmetros de um novo automato
Automaton getAutomaton();

// Imprime o estado de um automato
void printAutomaton(Automaton &automaton);

// Decide se a imagem será exibida no final da simulação
bool getImageOption();

// Exibe a mensagem de finalização de simulação
void promptEndGame();

#endif