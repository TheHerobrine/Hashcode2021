import { getScore, ISolution } from "./index";
import { parseFile } from "../parser";

describe("simulator/scoring", () => {
    test("it should compute the correct score", async () => {
        const pizzeria = await parseFile("a_example.in");
        const solution: ISolution = [
            { teamSize: 2, pizzas: [1, 4] },
            { teamSize: 3, pizzas: [0, 2, 3] },
        ];

        const score = getScore(solution, pizzeria);

        expect(score).toBe(65);
    });
});
