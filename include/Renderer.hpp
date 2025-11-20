#pragma once
#include "Maze.hpp"
#include <vector>

class Renderer {
public:
    void renderConsole(const Maze& maze, const std::vector<Point>& path) const;
};
