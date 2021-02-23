import {  parseFile } from "./index";

describe("parser", () => {
    test("it should parse the content correctly", async () => {
        const pizzeria = await parseFile("a_example.in");

        expect(pizzeria.teamsNumber[2]).toBe(1);
        expect(pizzeria.teamsNumber[3]).toBe(2);
        expect(pizzeria.teamsNumber[4]).toBe(1);
        expect(pizzeria.pizzas.length).toBe(5);
        expect(pizzeria.pizzas[0].index).toBe(0);
        expect(pizzeria.pizzas[0].ingredients.length).toBe(3);
        expect(pizzeria.pizzas[0].ingredients).toStrictEqual(["onion", "pepper", "olive"]);
    });
});
