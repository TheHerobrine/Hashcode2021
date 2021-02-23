export interface IPizzaType {
    ingredients: Array<string>
}

export interface IPizzeria {
    teamsNumber: {
        2: number,
        3: number,
        4: number
    },
    pizzas: Array<IPizzaType>
}

export interface IBufferLines extends Array<string> {
}
