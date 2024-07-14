line_1 = input()

chars = [ord(x) for x in line_1]
chars.sort()

def next():
    largest = 0
    replaceIdx = -1 
    global chars

    for i in range(len(chars)-1, -1, -1):
        if chars[i] < largest:
            replaceIdx = i  
            break;

        largest = max(chars[i], largest)

    if (replaceIdx == -1): 
        return False
    
    for i in range(len(chars)-1, -1, -1):
        if chars[i] > chars[replaceIdx]:
            temp = chars[i]
            chars[i] = chars[replaceIdx]
            chars[replaceIdx] = temp
            break;
   
    second_half = chars[replaceIdx+1:]
    second_half.sort()
    chars = chars[:replaceIdx+1] + second_half
    
    return True

count = 1 
results = []

results.append(''.join([chr(x) for x in chars]))

while next():
    count += 1
    results.append(''.join([chr(x) for x in chars]))

print(count)

for res in results:
    print(res)
