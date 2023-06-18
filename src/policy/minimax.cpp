#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"
using namespace std;


Move MiniMax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
    state->get_legal_actions();

    auto bestValue = dfsGetValue(state, depth);
    auto actions = state->legal_actions;
    
    return actions[bestValue.second];
}

pair<int, int> MiniMax::dfsGetValue(State *state, int depth){  //odd depth for max, even for min
    if(depth == 0){
        pair<int, int> p;
        p.first = state->evaluate();
        p.second = 0;
        return p;
    }
    if(depth % 2 == 1){ //search for max
        pair<int, int>bestValue;
        bestValue.first = -2e9;
        bestValue.second = 0;
        int n = 0;
        auto actions = state->legal_actions;
        for(auto it=actions.begin();it!=actions.end();it++){
            auto nextState = state->next_state(*it);
            int score = dfsGetValue(nextState, depth-1).first;
            if(score > bestValue.first){
                bestValue.first = score;
                bestValue.second = n;
            }
            n ++;
        }
        return bestValue;
    }else{  //search for min
        pair<int, int>bestValue;
        bestValue.first = 2e9;
        bestValue.second = 0;
        int n = 0;
        auto actions = state->legal_actions;
        for(auto it=actions.begin();it!=actions.end();it++){
            auto nextState = state->next_state(*it);
            int score = dfsGetValue(nextState, depth-1).first;
            if(score < bestValue.first){
                bestValue.first = score;
                bestValue.second = n;
            }
            n ++;
        }
        return bestValue;
    }
}