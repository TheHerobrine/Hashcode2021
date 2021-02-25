#include <gtest/gtest.h>

#include "../../src/solver/hugo/Solver.h"

void solve(string solutionName)
{
    Solver solver;
    solver.Load(solutionName + ".txt");
    solver.Solve();
    solver.savedSolution->writeSolution(solutionName + ".out");
}


TEST(solver, solve) {
    //solve("a");
    solve("b");
    //solve("c");
    //solve("d");
    //solve("e");
    //solve("f");
}

/*
TEST(solver, improve) {
    string solutionName = "e";

    Solver solver;
    solver.Load(solutionName + ".in");
    solver.LoadSolution(solutionName + ".out");
    solver.Improve(solutionName + ".out");
}
 */