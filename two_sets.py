def print_lists(list_1, list_2):
    print(len(list_1))
    for i in range(0, len(list_1)):
        print(list_1[i], end=" ")
    print()

    print(len(list_2))
    for i in range(0, len(list_2)):
        print(list_2[i], end=" ")
    print()

def two_sets():
    line_1 = input()

    nums = int(line_1)

    list_1_sum = 0
    list_1 = []

    list_2_sum = 0
    list_2 = []

    sum_check = 0

    for i in range(1, nums+1):
        sum_check += i

    if (sum_check % 2 == 1):
        print("NO")
        return

    for i in range(1, nums+1):
        if i % 2 == 1:
            list_1.append(i)
            list_1_sum += i
        if i % 2 == 0:
            list_2.append(i)
            list_2_sum += i

    list_sum_difference = list_1_sum - list_2_sum

    for i in range(abs(list_sum_difference)//2-1, -1, -1): 
        temp = list_2[i]
        list_2[i] = list_1[i]
        list_1[i] = temp

    if (list_sum_difference > 0):
        list_2.append(list_1.pop(list_1.index(list_sum_difference)))

    print("YES")
    print_lists(list_1, list_2)
        
two_sets()
