#include <gtest/gtest.h>
#include "../src/pizzeria/Pizzeria.h"

TEST(pizzeria, load)
{
    Pizzeria pizzeria;
    pizzeria.LoadFromFile("a_example.in");

    EXPECT_EQ(pizzeria.teamsNumber[2],1);
    EXPECT_EQ(pizzeria.teamsNumber[3],2);
    EXPECT_EQ(pizzeria.teamsNumber[4],1);

    EXPECT_EQ(pizzeria.pizzas.size(),5);
    EXPECT_EQ(pizzeria.pizzas[2]->index,2);
    EXPECT_EQ(pizzeria.pizzas[2]->ingredients.size(),3);

    EXPECT_EQ(pizzeria.pizzas[2]->ingredients[0]->name,"chicken");
    EXPECT_EQ(pizzeria.pizzas[2]->ingredients[1]->name,"mushroom");
    EXPECT_EQ(pizzeria.pizzas[2]->ingredients[2]->name,"pepper");
}