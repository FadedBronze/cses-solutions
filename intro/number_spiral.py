def number_spiral():
    line_1 = input()
    
    tests = int(line_1) 

    for _ in range(0, tests):
        test_case = [int(x) for x in input().split(" ")]
        
        layer = max(test_case[0], test_case[1]) - 1;

        y = layer * layer + layer + 1

        dim = layer % 2
        not_dim = (layer + 1) % 2

        print(y - test_case[dim] + test_case[not_dim])


number_spiral()
