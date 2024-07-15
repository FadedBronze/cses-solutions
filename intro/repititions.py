def repititions():    
    line_1 = input();

    largest_count = 1
    last_count = 1

    if len(line_1) == 0:
        print(0);
        return;

    last = line_1[0]

    for x in range(1, len(line_1)):
        if (line_1[x] == last):
            last_count += 1
        else:
            last = line_1[x]
                
            if (last_count > largest_count):
                largest_count = last_count 

            last_count = 1

    if (last_count > largest_count):
        largest_count = last_count 

    print(largest_count) 

repititions()
