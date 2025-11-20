#pragma once
#include <vector>
#include <random>

struct Cell {
    bool visited;
    bool wall;
};

struct Point {
    int x, y;
    friend bool operator==(const Point& a, const Point& b) {
        return a.x == b.x && a.y == b.y;
    }
};

class Maze {
public:
    Maze(int width, int height);
    void generate();
    bool isValid(int x, int y) const;
    void reset();
    int getWidth() const;
    int getHeight() const;
    const std::vector<std::vector<Cell>>& getGrid() const;
    Point getStart() const;
    Point getEnd() const;
private:
    int width, height;
    std::vector<std::vector<Cell>> grid;
    Point start, end;
    void carve(int x, int y);
};
