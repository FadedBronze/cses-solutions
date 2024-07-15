line_1 = input()
line_2 = input()

apples = [int(x) for x in line_2.split(" ")]

apples.sort()

mean = 0

def add_mean(x):
    global mean
    mean += x

[add_mean(x) for x in apples]

mean /= 2
solutions = []

def recurse(target, sum, count, apples, solutions):
    for i in range(0, len(apples) - count):
        apple = apples[len(apples) - count - 1 - i]

        if (apple + sum >= target):
            solutions.append((apple + sum) - target)
            continue;

        recurse(target, apple + sum, count + i + 1, apples, solutions)
     

recurse(mean, 0, 0, apples, solutions)

solutions.sort()

print(int(solutions[0]*2))
