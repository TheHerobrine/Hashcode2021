#include <gtest/gtest.h>
#include "../../src/solver/hugo/Solver.h"

TEST(solver, pizzeriaInstance) {
    Pizzeria pizzeria;
    pizzeria.LoadFromFile("a_example.in");

    PizzeriaInstance pizzeriaInstance(pizzeria);

    ASSERT_EQ(pizzeriaInstance.remainingTeam[2], pizzeria.teamsNumber[2]);
    ASSERT_EQ(pizzeriaInstance.remainingTeam[3], pizzeria.teamsNumber[3]);
    ASSERT_EQ(pizzeriaInstance.remainingTeam[4], pizzeria.teamsNumber[4]);

    ASSERT_EQ(pizzeriaInstance.availablePizzas[1]->index, pizzeria.pizzas[1]->index);
}

TEST(solver, solve_a) {
    Solver solver;
    solver.Load("a_example.in");
    solver.Solve();
}

TEST(solver, solve_b) {
    Solver solver;
    solver.Load("b_little_bit_of_everything.in");
    solver.Solve();
}

TEST(solver, solve_c) {
    Solver solver;
    solver.Load("c_many_ingredients.in");
    solver.Solve();
}

TEST(solver, solve_d) {
    Solver solver;
    solver.Load("d_many_pizzas.in");
    solver.Solve();
}

TEST(solver, solve_e) {
    Solver solver;
    solver.Load("e_many_teams.in");
    solver.Solve();
}