#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/Maze.hpp"
#include "../include/BFSSolver.hpp"

TEST_CASE("Maze dimensions", "[maze]") {
    Maze maze(11, 11);
    maze.generate();
    REQUIRE(maze.getGrid().size() == 11);
    REQUIRE(maze.getGrid()[0].size() == 11);
}

TEST_CASE("BFS solver finds a path", "[bfs]") {
    Maze maze(11, 11);
    maze.generate();
    BFSSolver solver;
    auto path = solver.solve(maze);
    REQUIRE(!path.empty());
}
