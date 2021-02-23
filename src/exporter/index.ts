import * as fs from "fs";
import * as path from "path";

const outputFolder = path.resolve(__dirname, "../../output");

export async function exportToFile(fileName: string, content:string)
{
    try {
        await fs.promises.access(outputFolder, fs.constants.F_OK);
    }
    catch (e) {
        await fs.promises.mkdir(outputFolder);
    }

    const filePath = path.join(outputFolder, fileName);
    await fs.promises.writeFile(filePath, content);
}
