#pragma once
#include "../state/state.hpp"
using namespace std;

class MiniMax{
    public:
    static Move get_move(State *state, int depth);
    static pair<int, int> dfsGetValue(State *state, int depth);
};