dctP = {
    "X" : 1, 
    "Y" : 2, 
    "Z" : 3, 
}

win = {
    "X" : "C", 
    "Y" : "A", 
    "Z" : "B", 
}

draw = {
    "X" : "A", 
    "Y" : "B", 
    "Z" : "C", 
}

lose = {
    "X" : "B", 
    "Y" : "C", 
    "Z" : "A", 
}
# with open('smol.txt') as f:
with open('input.txt') as f:
    ip = f.read()
    lst = ip.split("\n")
    ans = 0
    for l in lst:
        if (l==""): continue
        r1, r2 = l.split(" ")
        if (r2 == "Z"): 
            dct = win
            ans += 6
        elif (r2 == "Y"): 
            dct = draw
            ans += 3
        else: dct = lose
        for k, v in dct.items():
            if v == r1:
                res = k
        ans += dctP[res]

print(ans)


    