line_1 = input()

def move(a: int, b: int, c: int, times: int, moves: list, runs: int):
    if times == 0:
        return runs 

    runs = move(a, c, b, times - 1, moves, runs)
    moves.append([a, c]) 
    runs = move(b, a, c, times - 1, moves, runs)

    return runs + 1

n = int(line_1)

moves = []
runs = move(1, 2, 3, n, moves, 0)

print(runs)

for i in range(0, len(moves)):
    print(moves[i][0], moves[i][1])

