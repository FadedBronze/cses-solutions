path = input()

visited = [
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
    False, 
]

def valid(x, y, visited):
    return x < 7 and x >= 0 and y < 7 and y >= 0 and not visited[y * 7 + x]

def BRUTE(i, x, y, ol_visited):
    paths = 0
    curr = path[i]

    if i == 47:
        return 1
    
    visited = ol_visited.copy()
    visited[y * 7 + x] = True
    
    print(curr, i)
    
    if (curr == "U" or curr == "?") and valid(x, y+1, visited):
        paths += BRUTE(i+1, x, y+1, visited)
    
    if (curr == "D" or curr == "?") and valid(x, y-1, visited):
        paths += BRUTE(i+1, x, y-1, visited)

    if (curr == "L" or curr == "?") and valid(x-1, y, visited):
        paths += BRUTE(i+1, x-1, y, visited)
    
    if (curr == "R" or curr == "?") and valid(x+1, y, visited):
        paths += BRUTE(i+1, x+1, y, visited)    

    return paths

print(BRUTE(0, 0, 0, visited))
