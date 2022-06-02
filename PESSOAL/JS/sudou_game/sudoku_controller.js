class SudokuController { 
    constructor() {
        console.log("Created instance!")
        this.view = new SudokuView();
    }

    tables = []
    
    createSudoku() {
        let id = this.tables.length
        let model = new SudokuModel(id)
        this.view.createSudokuTable(id, model)
        this.tables.push(model)
    }

    setFixNumbers(input, id) {
        if (typeof input == "string")
            for (let i = 0; i < 81; i++) {
                this.tables[id].setNumber(i,input[i])
                this.view.setNumber(id, i, input[i])
            }   
            
        else if (typeof input == "object")
            for (let i = 0; i < 81; i++) {
                let number = input[Math.floor(i/9)][i%9]
                this.tables[id].setNumber(i,number)
                this.view.setNumber(id, i, number)
            }
    }
}

// SINGLETON DESIGN INSTANCE CONTROLL
var instance

function getController() {
    if (instance) return instance
    instance = createController()
    return instance
}

function createController() {
    var object = new SudokuController()
    return object
}