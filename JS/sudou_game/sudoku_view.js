class SudokuView {
    constructor () {
        this.base = document.getElementById("page")
    }

    createSudokuTable(id) {
        let bgHTML = document.createElement("div")
        bgHTML.className = "bgHTML"
        bgHTML.id = 'b' + id

        // TITLE
        let title = document.createElement("h1")
        title.innerText = "Sudoku"
        bgHTML.appendChild(title)

        // OUTTER TABLE
        let tableHTML = document.createElement("table")
        let idHTML = 0
        for (let i = 0; i < 3; i++) {
            let trHTML = document.createElement("tr")
            for (let j = 0; j < 3; j++) {
                let tdHTML = document.createElement("td")

                // INNER TABLE
                let table2HTML = document.createElement("table")
                for (let i = 0; i < 3; i++) {
                    let tr2HTML = document.createElement("tr")
                    for (let j = 0; j < 3; j++) {
                        let td2HTML = document.createElement("td")
                        
                        let numberHTML = document.createElement("input")
                        numberHTML.type = "number"
                        numberHTML.min = 1
                        numberHTML.max = 9
                        numberHTML.className = "numberLock"
                        numberHTML.id = 'n' + idHTML
                        idHTML += 1
                        numberHTML.innerText = 0
                        
                        td2HTML.appendChild(numberHTML)
                        tr2HTML.appendChild(td2HTML)
                    }
                    table2HTML.appendChild(tr2HTML)
                    tdHTML.appendChild(table2HTML)
                }
                trHTML.appendChild(tdHTML)
            }
            tableHTML.appendChild(trHTML)
        }
        bgHTML.appendChild(tableHTML)

        // CHECK BUTTON
        let checkbtnHTML = document.createElement("button")
        checkbtnHTML.className = "checkbutton"
        checkbtnHTML.innerText = "Validar"
        bgHTML.appendChild(checkbtnHTML)

        this.base.appendChild(bgHTML)
    }

    setNumber(id, i, number) {
        let elem = document.querySelector("#b" + id + ".bgHTML #n" + i)
        if (number == 0) {
            elem.value = ""
            elem.contentEditable = true;
            elem.className = "numberWrite"
        }
        else {
            elem.value = number
            elem.contentEditable = false;
            elem.className = "numberLock"
        }
    }

    getNumbers(id) {
        let y = []
        let x = []
        for (let i = 0; i < 81; i++) {
            if (i != 0 && i%9 == 0) {
                y.push(x)
                x = []
            }
            x.push(document.querySelector("#b" + id + ".bgHTML #n" + i).innerText)
        }
        return y
    }

}