class Sudoku {
    constructor(x, sudoku_name) {
        this.id = document.querySelectorAll("#page > .sudoku").length
        this.board = new Board()
        this.renderer = new Renderer(this.id, this.checkButton, sudoku_name)

        if (x)
            this.setNumbers(x)
    }
    
    setNumbers(string) {
        this.board.setNumbers(string)
        this.renderer.setNumbers(string)
    }

    checkRepeat(string) {
        for (let i = 0; i < string.length; i++) 
            for (let j = i+1; j < string.length; j++)
                if (i == j) return true
        return false
    }

    checkButton() {
        for (let i = 0; i < 9; i++) {
            let string = this.board.getBlock(i)
            this.checkRepeat(string)
        }
    }
}