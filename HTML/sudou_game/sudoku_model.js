class SudokuModel {
    constructor (id) {
        this.id = id
        this.data = [[ 0, 1, 2, 3, 4, 5, 6, 7, 8], // 0
                     [ 9,10,11,12,13,14,15,16,17], // 1
                     [18,19,20,21,22,23,24,25,26], // 2

                     [27,28,29,30,31,32,33,34,35], // 3
                     [36,37,38,39,40,41,42,43,44], // 4
                     [45,46,47,48,49,50,51,52,53], // 5

                     [54,55,56,57,58,59,60,61,62], // 6
                     [63,64,65,66,67,68,69,70,71], // 7
                     [72,73,74,75,76,77,78,79,80]] // 8
    }

    getBlock(x) {
        return this.data[x]
    }

    getRow(x) {
        let y = []

        y.push(this.data[Math.floor(x/3)*3+0][(x%3)*3+0])
        y.push(this.data[Math.floor(x/3)*3+0][(x%3)*3+1])
        y.push(this.data[Math.floor(x/3)*3+0][(x%3)*3+2])
        
        y.push(this.data[Math.floor(x/3)*3+1][(x%3)*3+0])
        y.push(this.data[Math.floor(x/3)*3+1][(x%3)*3+1])
        y.push(this.data[Math.floor(x/3)*3+1][(x%3)*3+2])
        
        y.push(this.data[Math.floor(x/3)*3+2][(x%3)*3+0])
        y.push(this.data[Math.floor(x/3)*3+2][(x%3)*3+1])
        y.push(this.data[Math.floor(x/3)*3+2][(x%3)*3+2])

        return y
    }
    
    getCol(x) {
        let y = []

        y.push(this.data[Math.floor(x/3)+0][(x+0%3)*3])
        y.push(this.data[Math.floor(x/3)+0][(x+1%3)*3])
        y.push(this.data[Math.floor(x/3)+0][(x+2%3)*3])
        
        y.push(this.data[Math.floor(x/3)+3][(x+0%3)*3])
        y.push(this.data[Math.floor(x/3)+3][(x+1%3)*3])
        y.push(this.data[Math.floor(x/3)+3][(x+2%3)*3])
        
        y.push(this.data[Math.floor(x/3)+6][(x+0%3)*3])
        y.push(this.data[Math.floor(x/3)+6][(x+1%3)*3])
        y.push(this.data[Math.floor(x/3)+6][(x+2%3)*3])

        return y
    }
    
    getNumber(x) {
        return this.data[Math.floor(x/9)][x%9]      
    }

    setNumber(x,number) {
        this.data[Math.floor(x/9)][x%9] = number
    }

}