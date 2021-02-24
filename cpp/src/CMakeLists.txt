add_executable(shell-app
        main.cpp
        pizzeria/Pizzeria.h
        solution/Solution.h
        solver/hugo/Solver.h
        )

include_directories(
        ${CMAKE_SOURCE_DIR}/include
)