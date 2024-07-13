line_1 = input()

letters = {}

for c in line_1:
    if (c in letters):
        letters[c] += 1
    else:
        letters[c] = 1

oddCount = 0
result = ''
odd = ''
no_solution = False

for c, value in letters.items():
    if (value % 2 != 0):
        oddCount += 1
        odd = c

    result = c*(value//2) + result
    result = result + c*(value//2)
    
    if (oddCount == 2):
        no_solution = True
        break;

if no_solution:
    print("NO SOLUTION")
else:
    result = result[:len(result)//2] + odd + result[len(result)//2:]
    print(result)
    

