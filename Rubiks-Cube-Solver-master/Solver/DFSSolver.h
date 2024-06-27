#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_SOLVER_DFSSOLVER_H

template<typename T, typename H>
class DFSSolver 
{
    private:

        vector<RubiksCube::Move> moves;
        int max_search_depth;

        bool dfs(int dep)
        {
            if(rubiksCube.isSolved()) return true;
            if(dep > max_search_depth) return false;
            for(int i=0;i<18;i++)
            {
                rubiksCube.move(RubiksCube::Move(i));
                moves.push_back(RubiksCube::Move(i));
                if(dfs(dep+1)) return true;
                moves.pop_back();
                rubiksCube.invert(RubiksCube::Move(i));
            }
            return false;
        } 

    public:
        T rubiksCube;

        DFSSolver(T _rubiksCube, int _max_search_depth = 8) 
        {
            rubiksCube = _rubiksCube;
            max_search_depth = _max_search_depth;
        }

        vector<RubiksCube::Move> solve() 
        {
            dfs(1);
            return moves;
        }
};

#endif