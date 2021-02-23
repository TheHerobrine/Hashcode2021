import { solve } from "./index";

describe("solver/hugo", () => {
    test("solve A", async () => {
        await solve("a_example.in");
    });

    test("solve B", async () => {
        await solve("b_little_bit_of_everything.in");
    });

    test("solve C", async () => {
        await solve("c_many_ingredients.in");
    });

    test("solve D", async () => {
        await solve("d_many_pizzas.in");
    });

    test("solve E", async () => {
        await solve("e_many_teams.in");
    });
});
