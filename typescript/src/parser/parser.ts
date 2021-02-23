import * as fs from "fs";
import { IBufferLines, IPizzaType, IPizzeria } from "./schema";
import * as path from "path";

const inputFolder = path.resolve(__dirname, "../../input");

export async function parseFile(fileName: string): Promise<IPizzeria> {
    const fileContent = await getFileContent(fileName);
    return parseContent(fileContent);
}

export async function getFileContent(fileName: string): Promise<IBufferLines> {
    const filePath = path.join(inputFolder, fileName);
    const fileContent = await fs.promises.readFile(filePath);
    const buffer = Buffer.from(fileContent);
    return buffer.toString().split("\n");
}

export function parseContent(content: IBufferLines): IPizzeria {
    const pizzeria: IPizzeria = { teamsNumber: { 2: 0, 3: 0, 4: 0 }, pizzas: [] };

    parseHeader(content[0]);
    for (let lineNumber = 1; lineNumber < content.length; lineNumber++) {
        if (content[lineNumber].trim()) {
            parseLine(content[lineNumber], lineNumber - 1);
        }
    }

    function parseHeader(header: string) {
        const headerData = header.trim().split(" ");
        pizzeria.teamsNumber[2] = parseInt(headerData[1]);
        pizzeria.teamsNumber[3] = parseInt(headerData[2]);
        pizzeria.teamsNumber[4] = parseInt(headerData[3]);
    }

    function parseLine(line: string, index: number) {
        const lineData = line.trim().split(" ");
        lineData.shift();
        const pizzaType: IPizzaType = { index, ingredients: lineData };
        pizzeria.pizzas.push(pizzaType);
    }

    return pizzeria;
}
