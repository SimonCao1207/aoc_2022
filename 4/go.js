var fs = require("fs");

function part1(err, data){
    const cnt = data.split("\n").reduce((acc, cur) => {
        const p1 = cur.split(",")[0], p2 = cur.split(",")[1]
        if (p2 == undefined) return acc;
        const l1 = parseInt(p1.split("-")[0]), r1 = parseInt(p1.split("-")[1]);
        const l2 = parseInt(p2.split("-")[0]), r2 = parseInt(p2.split("-")[1]);
        if ((l1 <= l2 && r1>=r2) || (l1>=l2 && r1<=r2))
            return acc + 1
        else return acc
    }, 0);
    console.log("Final sol of part 1: ", cnt);
}

function part2(err, data){
    const cnt = data.split("\n").reduce((acc, cur) => {
        const p1 = cur.split(",")[0], p2 = cur.split(",")[1]
        if (p2 == undefined) return acc;
        const l1 = parseInt(p1.split("-")[0]), r1 = parseInt(p1.split("-")[1]);
        const l2 = parseInt(p2.split("-")[0]), r2 = parseInt(p2.split("-")[1]);
        if ((r1<l2) || (r2<l1))
            return acc
        else return acc + 1
    }, 0);
    console.log("Final sol of part 2: ", cnt);
}


// fs.readFile('input.txt', 'utf8', (err, data) => part1(err, data));
fs.readFile('input.txt', 'utf8', (err, data) => part2(err, data));

