n = int(input())
L = input().split()
L = [int(x) for x in L]
result = 0

def big(index):
    x = L[index]
    for y in range(0, index):
        if L[y] > x:
            return False
    return True
    

def sml(index):
    x = L[index]
    for y in range(index + 1, n):
        if L[y] < x:
            return False
    return True

for index, z in enumerate(L):
    a = sml(index)
    b = big(index)
    if a and b:
        result += 1
        
print(result)