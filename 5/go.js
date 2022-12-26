var fs = require("fs")


function isLetter(str) {
    return str.length === 1 && str.match(/[a-z]/i);
}

function applyInstruction(instructions, map, part=1){
    const newMap = JSON.parse(JSON.stringify(map))
    let move, from, to
    instructions.forEach(e => {
        [move, from, to] = e;
        let arr = Array()
        for(let i=0; i < move; i++){
            let firstEl = newMap[from].shift()
            if (part == 2)
                arr.push(firstEl)
            else arr.unshift(firstEl)
        }
        newMap[to].unshift(...arr)
    })
    return newMap
}
function main(err, data){
    let splitted =  data.split(/\n\s*\n/)
    let map, instructions;
    splitted.forEach((capture, i) => {
        if (i>0) {
            // READ INSTRUCTION
            let move, from, to;
            instructions = capture.split("\n").reduce((obj, x) => {
                move =  x.split(" ")[1]
                from = x.split(" ")[3]
                to = x.split(" ")[5]
                const arr = Array(move, from , to)
                obj.push(arr)
                return obj
            }, [])
        }
        else {
            // READ MAP
            const blockArray = capture.split("\n").slice(-1)[0].trim().split("  ")
            const numBlock = blockArray.length
            map = blockArray.reduce((obj, x) => {
                obj[parseInt(x)] = Array()
                return obj;
            }, {});

            capture.split("\n").forEach(e => {
                Array(e).map(l => {
                    let arr = l.split("")
                    for (let i = 0; i < 4*numBlock; i++){
                        if (i%4==1)
                            if (isLetter(arr[i]))
                                map[Math.floor(i/4)+1].push(arr[i])
                    }        
                })
            })
        }
    });
    let part = 1 
    const newMap = applyInstruction(instructions, map, part=part)
    const ans = Object.values(newMap).reduce((obj, x) => obj.concat(x[0]), "")
    
    console.log("Final ans of part %i is: ", part, ans);
}


// fs.readFile('smol.txt', 'utf8', main)
fs.readFile('input.txt', 'utf8', main)