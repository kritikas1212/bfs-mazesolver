cmake_minimum_required(VERSION 3.16)
project(BFS_Maze_Solver)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(BFS_Maze_Solver
    src/main.cpp
    src/Maze.cpp
    src/BFSSolver.cpp
    src/Renderer.cpp
)

enable_testing()
add_subdirectory(tests)
