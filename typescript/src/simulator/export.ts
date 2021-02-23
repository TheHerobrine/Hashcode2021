import {ISolution} from "./schema";

export function exportSolution(solution: ISolution): string {
    let exportString = "";

    exportString += solution.length;

    for (const delivery of solution)
    {
        exportString += "\n" + delivery.teamSize + " ";
        exportString += delivery.pizzas.join(" ");
    }

    return exportString;
}
