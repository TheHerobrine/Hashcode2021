import { exportSolution, ISolution } from "./index";

describe("simulator/export", () => {
    test("it should export the solution", async () => {
        const solution: ISolution = [
            { teamSize: 2, pizzas: [1, 4] },
            { teamSize: 3, pizzas: [0, 2, 3] },
        ];

        const exportedSolution = exportSolution(solution);

        expect(exportedSolution).toBe(`2\n2 1 4\n3 0 2 3`);
    });
});
