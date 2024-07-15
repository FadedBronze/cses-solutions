line_1 = input()

for i in range(0, int(line_1)):
    next = input() 
    nums = [int(x) for x in next.split(' ')] 

    a = max(nums[0], nums[1])
    b = min(nums[0], nums[1])
    
    c = 2 * b - a

    if c >= 0 and c % 3 == 0:
        print("YES")
    else:
        print("NO")
