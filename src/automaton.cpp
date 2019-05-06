#include "automaton.h"
#include "cell.h"

Automaton getRandomAutomaton(const unsigned int num_cells)
{
    Automaton automaton;
    automaton.num_cells = num_cells;
    automaton.cells = new Cell[num_cells];
    for (unsigned int iii = 0; iii < num_cells; ++iii)
    {
        automaton.cells[iii].state = getRandomState();
    }
    return automaton;
}

Automaton updateAutomaton(Automaton &automaton, Rule &rule)
{
    Automaton new_automaton;
    new_automaton.num_cells = automaton.num_cells;
    new_automaton.cells = new Cell[automaton.num_cells];

    int left_state, center_state, right_state, rule_index;

    for (unsigned int iii = 0; iii < automaton.num_cells; ++iii)
    {
        left_state = (automaton.cells[(iii > 0 ? iii - 1 : automaton.num_cells - 1)].state == CellState::ALIVE) ? 1 : 0;
        center_state = (automaton.cells[iii].state == CellState::ALIVE ? 1 : 0);
        right_state = (automaton.cells[(iii == automaton.num_cells - 1 ? 0 : iii + 1)].state == CellState::ALIVE) ? 1 : 0;
        rule_index = 4 * left_state + 2 * center_state + right_state;
        new_automaton.cells[iii].state = (rule.states[rule_index] == true ? CellState::ALIVE : CellState::DEAD);
    }

    return new_automaton;
}