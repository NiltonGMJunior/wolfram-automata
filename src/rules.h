#ifndef RULES_H
#define RULES_H

#include "cell.h"
#include <string>

/*  Define uma estrutura padrão para cada regra
*   A regra é composta por um vetor de 8 elementos, representados pela conversão em binário dos índices do vetor states
*
*   0 - 000
*   1 - 001
*   2 - 010
*   3 - 011
*   4 - 100
*   5 - 101
*   6 - 110
*   7 - 111
*   
*   Cada um dos três bits que representam um estado define se a célula correspondente está viva ou morta
*   O valor armazenado no vetor states é o estado da célula central para a próxima iteração, dado o seu estado atual e o estado das células vizinhas à esquerda e direita
*   Por exemplo, o segundo elemento do vetor states define o que ocorrerá com a célula central na iteração seguinte considerando:
*   Índice: 1
*   Estado atual: 001 (implica que a célula à esquerda e a célula central estão mortas, e a célula à direita está viva)
*   Próximo estado: states[1] (pode ser DEAD ou ALIVE (false e true, respectivamente)), indicando se, nas circunstâncias acima, a célula permanecerá morta (DEAD) ou se tornará viva (ALIVE)  
*/ 
struct Rule
{       
    bool states[8];
};

Rule getRandomRule();

#endif