#include "BFSSolver.hpp"
#include <queue>
#include <unordered_map>

std::vector<Point> BFSSolver::solve(const Maze& maze) {
    auto& grid = maze.getGrid();
    Point start = maze.getStart();
    Point end = maze.getEnd();
    int h = maze.getHeight(), w = maze.getWidth();

    std::queue<Point> q;
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
    std::vector<std::vector<Point>> parent(h, std::vector<Point>(w, {-1, -1}));

    q.push(start);
    visited[start.x][start.y] = true;

    static const std::vector<std::pair<int, int>> dirs = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    bool found = false;
    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        if (cur == end) { found = true; break; }
        for (auto [dx, dy] : dirs) {
            int nx = cur.x + dx, ny = cur.y + dy;
            if (maze.isValid(nx, ny) && !grid[nx][ny].wall && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                parent[nx][ny] = cur;
            }
        }
    }

    std::vector<Point> path;
    if (!found) return path;
    Point cur = end;
    while (!(cur == start)) {
        path.push_back(cur);
        cur = parent[cur.x][cur.y];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}
