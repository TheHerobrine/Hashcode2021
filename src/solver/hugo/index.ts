import { IPizzeria, parseFile } from "../../parser";
import { cloneDeep } from "lodash";
import { exportSolution, getScore, ISolution, ITeamDelivery } from "../../simulator";
import { exportToFile } from "../../exporter";

export async function solve(fileName: string): Promise<void> {
    const pizzeria = await parseFile(fileName);

    const tryNumber = 10;
    let maxScore = 0;

    let bestSolution: ISolution = [];

    for (let i=0; i<tryNumber; i++)
    {
        const solution = generateRandomSolution(await cloneDeep(pizzeria));
        const score = getScore(solution, pizzeria);
        if (score > maxScore)
        {
            maxScore = score;
            bestSolution = solution;
        }
    }


    console.log({bestSolution, maxScore});

    const exportedSolution = exportSolution(bestSolution);
    await exportToFile(fileName, exportedSolution);
}

function generateRandomSolution(pizzeria: IPizzeria): ISolution {
    const solution: ISolution = [];

    while (isSolutionPossible()) {
        const maxRandom = Math.min(pizzeria.pizzas.length - 2, 2) + 1;
        const teamSize = Math.floor(Math.random() * maxRandom) + 2 as 2 | 3 | 4;

        if (pizzeria.teamsNumber[teamSize] > 0) {
            const teamDelivery: ITeamDelivery = { teamSize, pizzas: [] };

            for (let i = 0; i < teamSize; i++) {
                const randomPizzaIndex = Math.floor(Math.random() * pizzeria.pizzas.length);
                teamDelivery.pizzas.push(pizzeria.pizzas[randomPizzaIndex].index);
                pizzeria.pizzas.splice(randomPizzaIndex, 1);
            }
            solution.push(teamDelivery);
            pizzeria.teamsNumber[teamSize]--;
        }
    }

    return solution

    function isSolutionPossible(): boolean {
        const possibleTeamNumber = [2, 3, 4];
        for (const teamNumber of possibleTeamNumber) {
            if (pizzeria.teamsNumber[teamNumber] > 0 && pizzeria.pizzas.length >= teamNumber) {
                return true;
            }
        }
        return false;
    }
}
