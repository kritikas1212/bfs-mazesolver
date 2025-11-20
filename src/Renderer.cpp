#include "Renderer.hpp"
#include <iostream>

void Renderer::renderConsole(const Maze& maze, const std::vector<Point>& path) const {
    auto& grid = maze.getGrid();
    int h = maze.getHeight(), w = maze.getWidth();
    std::vector<std::vector<char>> display(h, std::vector<char>(w, '#'));

    // Mark path
    for (auto& p : path) display[p.x][p.y] = '*';

    display[maze.getStart().x][maze.getStart().y] = 'S';
    display[maze.getEnd().x][maze.getEnd().y] = 'E';

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!grid[i][j].wall) {
                if (display[i][j] == '#')
                    std::cout << " ";
                else if (display[i][j] == 'S')
                    std::cout << "\033[32mS\033[0m"; // Green
                else if (display[i][j] == 'E')
                    std::cout << "\033[31mE\033[0m"; // Red
                else if (display[i][j] == '*')
                    std::cout << "\033[34m*\033[0m"; // Blue
            } else std::cout << "#";
        }
        std::cout << "\n";
    }
}
