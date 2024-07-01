def permutations():
    line_1 = int(input())

    if (line_1 == 1):
        print("1");
        return

    if (line_1 <= 3):
        print("NO SOLUTION")
        return

    for x in range(2, line_1+1, 2):
        print(x, end=" ")

    for x in range(1, line_1+1, 2):
        print(x, end=" ")

permutations()
