line_1 = input()
line_2 = input()

n = int(line_1)
nums = [int(num) for num in line_2.split(" ")]

acc = 0;

for i in range(1, n+1):
    acc += i;

num_sum = 0;

for i in range(0, n - 1):
    num_sum += nums[i]

print(acc - num_sum);
