line_1 = input()
num = int(line_1)

for i in range(0, 2**num):
    gray_code = 0

    for j in range(0, num):
        val = 2**j
        bit = (i//val) % 2 ^ (i//(val*2)) % 2
        gray_code ^= (val * bit)

    binary = bin(gray_code)[2:]
    print("0"*(num-len(binary)) + binary)

