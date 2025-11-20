#include "Maze.hpp"

Maze::Maze(int w, int h)
    : width(w), height(h), grid(h, std::vector<Cell>(w, {false, true})) {
    start = {1, 1};
    end = {height - 2, width - 2};
}

bool Maze::isValid(int x, int y) const {
    return x >= 0 && x < height && y >= 0 && y < width;
}

void Maze::reset() {
    for (auto& row : grid)
        for (auto& cell : row)
            cell = {false, true};
    start = {1, 1};
    end = {height - 2, width - 2};
}

int Maze::getWidth() const { return width; }
int Maze::getHeight() const { return height; }
const std::vector<std::vector<Cell>>& Maze::getGrid() const { return grid; }
Point Maze::getStart() const { return start; }
Point Maze::getEnd() const { return end; }

// Recursive Backtracker Maze Generation
void Maze::generate() {
    reset();
    carve(start.x, start.y);
    grid[start.x][start.y].wall = false;
    grid[end.x][end.y].wall = false;
}

// Direction deltas (N, S, E, W)
static const std::vector<std::pair<int, int>> directions = {
    {-2, 0}, {2, 0}, {0, -2}, {0, 2}
};

void Maze::carve(int x, int y) {
    grid[x][y].wall = false;
    grid[x][y].visited = true;
    std::vector<int> order = {0, 1, 2, 3};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order.begin(), order.end(), g);

    for (int idx : order) {
        int nx = x + directions[idx].first;
        int ny = y + directions[idx].second;
        if (isValid(nx, ny) && grid[nx][ny].wall && !grid[nx][ny].visited) {
            grid[x + directions[idx].first / 2][y + directions[idx].second / 2].wall = false;
            carve(nx, ny);
        }
    }
}
