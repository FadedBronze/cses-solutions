def out_of_bounds(x, y, x2, y2, size):
    return (x >= size or y >= size or x < 0 or y < 0) or (x * size + y) <= (x2 * size + y2)

def two_knights(size):
    if size <= 1:
        print("0");
        return;

    count = 0
     
    for x in range(0, size):
        for y in range(0, size):
            in_bounds = 8

            if out_of_bounds(x + 1, y + 2, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x - 1, y + 2, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x + 1, y - 2, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x - 1, y - 2, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x + 2, y + 1, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x + 2, y - 1, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x - 2, y + 1, x, y, size):
                in_bounds -= 1 
            if out_of_bounds(x - 2, y - 1, x, y, size):
                in_bounds -= 1 

            count += size * size - in_bounds - (x * size + y) - 1
    
    print(count) 


line_1 = input()
size = int(line_1)

for x in range(1, size+1):
    two_knights(x)
