class Renderer {
    constructor(id, checkButtonFunction, sudoku_name) {
        this.id = id
        this.checkButtonFunction = checkButtonFunction
        this.sudoku_name = sudoku_name
        this.renderSudoku()
    }

    renderBlock(x,y) {
        let blockHTML = document.createElement("table")

        for (let i = 0; i < 3; i++) {
            let row = document.createElement("tr")
            for (let j = 0; j < 3; j++) {
                let display = document.createElement("td")
    
                let numero = document.createElement("div")
                numero.className = "numero"
                numero.id = ["n"]
                numero.id += [x*3+i]
                numero.id += [y*3+j]
    
                display.appendChild(numero)
                row.appendChild(display)
            }
            blockHTML.appendChild(row)
        }
        return blockHTML
    }
    
    renderSudoku() {
        let page = document.getElementById("page")
        let sudoku = document.createElement("div")
        sudoku.className = "sudoku"
        sudoku.id = "r"+this.id
        let table = document.createElement("table")
        table.className = "table"

        let title = document.createElement("h1")
        if (this.sudoku_name) title.innerText = "Sudoku \"" + this.sudoku_name + "\""
        else title.innerText = "Sudoku"
        title.className = "title"
        sudoku.appendChild(title)

        for (let i = 0; i < 3; i++) {
            let row = document.createElement("tr")
            for (let j = 0; j < 3; j++) {
                let display = document.createElement("td")
                display.appendChild( this.renderBlock(i,j) )
                row.appendChild(display)
            }
            table.appendChild(row)
        }
        sudoku.appendChild(table)

        let checkButton = document.createElement("input")
        checkButton.type = "button"
        checkButton.value = "Validar"
        checkButton.className = "checkbutton"
        checkButton.addEventListener("click", this.checkButtonFunction) 
        sudoku.appendChild(checkButton)

        page.appendChild(sudoku)
    }

    setNumber(x,y,number) {
        let string = [x] + [y]

        let target_string = "#r"+this.id+" #n"+string
        let target = document.querySelector(target_string)
        if (number != 0) {
            target.innerText = number
        }
        else {
            target.style.color = "white"
            target.contentEditable = true
        }
    }

    setNumbers(string) {
        for (let i = 0; i < 9; i++)
            for (let j = 0; j < 9; j++)
                this.setNumber(i,j,string[i*9+j])
    }
}