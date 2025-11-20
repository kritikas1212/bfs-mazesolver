#include "Maze.hpp"
#include "BFSSolver.hpp"
#include "Renderer.hpp"
#include <iostream>
#include <memory>

int main() {
    int width = 21, height = 21; // Odd numbers for best results
    Maze maze(width, height);
    maze.generate();

    std::unique_ptr<BFSSolver> solver = std::make_unique<BFSSolver>();
    auto path = solver->solve(maze);

    Renderer renderer;
    renderer.renderConsole(maze, path);

    if (path.empty())
        std::cout << "\nNo path found from Start to End!\n";
    else
        std::cout << "\nMaze solved! Path length: " << path.size() << "\n";
    return 0;
}
