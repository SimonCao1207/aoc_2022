from aocd import submit
with open('input.txt') as f:
# with open('smol.txt') as f:
    ip = f.read()
    lst = ip.split("\n")
    lstSum = []
    currentS = 0
    for e in lst:
        if (e == ""):
            # ans = max(ans, currentS)
            lstSum.append(currentS)
            currentS = 0
        else:
            currentS += int(e)
    lstSum.sort()
    ans = sum(lstSum[-3:])
    print(ans) 

# submit(ans, day=1, year=2022)