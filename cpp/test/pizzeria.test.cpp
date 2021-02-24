#include <gtest/gtest.h>
#include "../src/pizzeria/Pizzeria.h"

TEST(pizzeria, load)
{
    Pizzeria pizzeria;
    pizzeria.LoadFromFile("a_example.in");

    ASSERT_EQ(pizzeria.teamsNumber[2],1);
    ASSERT_EQ(pizzeria.teamsNumber[3],2);
    ASSERT_EQ(pizzeria.teamsNumber[4],1);

    ASSERT_EQ(pizzeria.pizzas.size(),5);
    ASSERT_EQ(pizzeria.pizzas[2]->index,2);
    ASSERT_EQ(pizzeria.pizzas[2]->ingredients.size(),3);

    ASSERT_EQ(pizzeria.pizzas[2]->ingredients[0]->name,"chicken");
    ASSERT_EQ(pizzeria.pizzas[2]->ingredients[1]->name,"mushroom");
    ASSERT_EQ(pizzeria.pizzas[2]->ingredients[2]->name,"pepper");
}