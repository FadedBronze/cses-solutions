line_1 = input()
line_2 = input()
line_3 = input()
line_4 = input()
line_5 = input()
line_6 = input()
line_7 = input()
line_8 = input()

grid = [line_1, line_2, line_3, line_4, line_5, line_6, line_7, line_8]

n = 8;

def BRUTE(ln, p_lr, p_rl, p_cs) -> int:
    if ln == 8:
        return 1
    
    perms = 0 
 
    for i in range(0, n):
        x = i
        y = ln

        if p_cs[x] == True:
            continue

        if p_lr[x + y] == True:
            continue

        if p_rl[(8-x) + y] == True:
            continue

        if grid[y][x] == "*":
            continue

        lr = p_lr.copy()
        rl = p_rl.copy()
        cs = p_cs.copy()

        cs[x] = True
        lr[x + y] = True
        rl[(8-x) + y] = True

        perms += BRUTE(ln + 1, lr, rl, cs)

    return perms

print(BRUTE(0, 
    [False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False], 
    [False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False],
    [False, False, False, False, False, False, False, False],
))
