import { ISolution } from "./schema";
import { IPizzeria } from "../parser/schema";

export function getScore(solution: ISolution, pizzeria:IPizzeria)
{
    let score = 0;

    for (const delivery of solution)
    {
        const ingredients = new Set();
        for (const pizza of delivery.pizzas)
        {
            pizzeria.pizzas[pizza].ingredients.forEach(ingredients.add, ingredients);
        }

        score += Math.pow(ingredients.size, 2);
    }

    return score;
}
