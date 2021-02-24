#include <gtest/gtest.h>
#include "../src/pizzeria/Pizzeria.h"
#include "../src/solution/Solution.h"

TEST(solution, write) {
    Pizzeria pizzeria;
    pizzeria.LoadFromFile("a_example.in");

    Solution solution;

    {
        Delivery delivery;
        delivery.teamSize = 2;
        delivery.pizzas.push_back(&pizzeria.pizzas[1]);
        delivery.pizzas.push_back(&pizzeria.pizzas[4]);
        solution.deliveries.push_back(delivery);
    }

    {
        Delivery delivery;
        delivery.teamSize = 3;
        delivery.pizzas.push_back(&pizzeria.pizzas[0]);
        delivery.pizzas.push_back(&pizzeria.pizzas[2]);
        delivery.pizzas.push_back(&pizzeria.pizzas[3]);
        solution.deliveries.push_back(delivery);
    }

    solution.writeSolution("toast.out");
}

TEST(solution, score) {
    Pizzeria pizzeria;
    pizzeria.LoadFromFile("a_example.in");

    Solution solution;

    {
        Delivery delivery;
        delivery.teamSize = 2;
        delivery.pizzas.push_back(&pizzeria.pizzas[1]);
        delivery.pizzas.push_back(&pizzeria.pizzas[4]);
        solution.deliveries.push_back(delivery);
    }

    {
        Delivery delivery;
        delivery.teamSize = 3;
        delivery.pizzas.push_back(&pizzeria.pizzas[0]);
        delivery.pizzas.push_back(&pizzeria.pizzas[2]);
        delivery.pizzas.push_back(&pizzeria.pizzas[3]);
        solution.deliveries.push_back(delivery);
    }

    ASSERT_EQ(solution.getScore(), 65);
}