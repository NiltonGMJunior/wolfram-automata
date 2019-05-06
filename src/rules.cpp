#include "rules.h"
#include "string"
#include <cmath>

Rule getRandomRule()
{
    Rule rule;
    for (unsigned int iii = 0; iii < 8; ++iii)
        rule.states[iii] = (rand() % 2 == 0) ? true : false;
    return rule;
}