def increasing_array():
    line_1 = int(input())
    line_2 = input()

    nums = [int(x) for x in line_2.split(' ')] 

    if (line_1 == 0):
        return 0

    last = nums[0]
    min_moves = 0

    for i in range(1, line_1):
        if (nums[i] < last):
            min_moves += last - nums[i]
        else:
            last = nums[i] 

    print(min_moves)

increasing_array()
