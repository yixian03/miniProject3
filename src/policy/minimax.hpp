#pragma once
#include "../state/state.hpp"

class MiniMax{
    public:
    static Move get_move(State *state, int depth);
    static int dfsGetValue(State *state, int depth);
};