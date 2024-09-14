def digit_query(N):
    base = 0
    i = 1

    while True:
        new_base = pow(10, i) * i

        for j in range(i-1, 0, -1):
            new_base -= pow(10, j)
 
        if new_base > N:
            break;

        base = new_base
        i += 1

    if base == 0:
        base = 1

    q = (N - base) // i + pow(10, i-1) 
    r = (N - base) % i

    return q // pow(10, i - r - 1) % 10

n = int(input())

for i in range(0, n):
    N = int(input())
    print(digit_query(N))
