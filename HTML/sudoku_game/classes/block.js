class Block {
    constructor() {
        this.data = [[0,0,0],
                     [0,0,0],
                     [0,0,0]]
    }

    getRow(x) {
        let string =  [this.data[x][0]]
            string += [this.data[x][1]]
            string += [this.data[x][2]]
        return string
    }

    getCol(x) {
        let string =  [this.data[0][x]]
            string += [this.data[1][x]] 
            string += [this.data[2][x]]
        return string
    }

    getBlock() {
        let string = []
        let x = 0
        while (x < 9) {
            string += [this.data[Math.floor(x/3)][x%3]]
            x += 1
        }
        return string
    }

    setNumber(x,y,number) {
        this.data[x][y] = number
    }

}