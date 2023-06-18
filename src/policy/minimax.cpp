#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"
#include <queue>
#include <stack>
using namespace std;


Move MiniMax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
    state->get_legal_actions();

    
}

int MiniMax::dfsGetValue(State *state, int depth){  //odd depth for max, even for min
    if(depth == 0)
        return state->evaluate();
    if(depth % 2 == 1){ //search for max
        pair<int, int>bestValue;
        bestValue.first = -2e9;
        int n = 0;
        auto actions = state->legal_actions;
        for(auto it=actions.begin();it!=actions.end();it++){
            auto nextState = state->next_state(*it);
            int score = dfsGetValue(nextState, depth-1);
            if(score > bestValue.first){
                bestValue.first = score;
                bestValue.second = n;
            }
            n ++;
        }
        return bestValue.first;
    }else{  //search for min
        pair<int, int>bestValue;
        bestValue.first = 2e9;
        int n = 0;
        auto actions = state->legal_actions;
        for(auto it=actions.begin();it!=actions.end();it++){
            auto nextState = state->next_state(*it);
            int score = dfsGetValue(nextState, depth-1);
            if(score < bestValue.first){
                bestValue.first = score;
                bestValue.second = n;
            }
            n ++;
        }
        return bestValue.first;
    }
}