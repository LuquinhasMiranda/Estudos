class Board {
    constructor() {
        
        this.data = [[new Block, new Block, new Block],
                     [new Block, new Block, new Block],
                     [new Block, new Block, new Block]]
    }

    getRow(x) {
        let string =  [this.data[Math.floor(x/3)][0].getRow(x)] 
            string += [this.data[Math.floor(x/3)][1].getRow(x)] 
            string += [this.data[Math.floor(x/3)][2].getRow(x)]
        return string
    }
    
    getCol(x) {
        let string =  [this.data[0][Math.floor(x/3)].getCol(x)] 
            string += [this.data[1][Math.floor(x/3)].getCol(x)] 
            string += [this.data[2][Math.floor(x/3)].getCol(x)]
        return string
    }

    getBlock(x) {
        let string = [this.data[Math.floor(x/3)][x%3].getBlock()]
        return string
    }

    setNumber(x,y,number) {
        this.data[Math.floor(x/3)][Math.floor(y/3)].setNumber(x%3,y%3,number)
    }

    setNumbers(string) {
        for (let i = 0; i < 9; i++)
            for (let j = 0; j < 9; j++)
                this.setNumber(i,j,string[i*9+j])
    }

    checkButton() {
        console.log(id)
    }

    teste() {
        return "teste"
    }

}