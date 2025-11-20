#pragma once
#include "Maze.hpp"
#include <vector>

class BFSSolver {
public:
    std::vector<Point> solve(const Maze& maze);
};
