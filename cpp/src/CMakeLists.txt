add_executable(shell-app
        main.cpp
        world/World.h
        world/WorldSimulation.h
        solution/Solution.cpp
        solution/Solution.h
        )

include_directories(
        ${CMAKE_SOURCE_DIR}/include
)