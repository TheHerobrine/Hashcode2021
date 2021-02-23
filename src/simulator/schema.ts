export type ISolution = Array<ITeamDelivery>;

export interface ITeamDelivery {
    teamSize: 2 | 3 | 4,
    pizzas: Array<number>
}
