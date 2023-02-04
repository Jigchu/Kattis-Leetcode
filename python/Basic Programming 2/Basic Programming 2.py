import math
z = input().split()
A = input().split()
N = int(z[0])
t = int(z[1])
A = list(map(int, A))
A.sort()
TF = False

if t == 1:
    a = [x for x in A if x < 7777]
    a.reverse()
    for p in a:
        X = p
        a.reverse()
        for q in a:
            Y = q
            if X + Y == 7777:
                TF = True
                break
            a.reverse()
    if TF :
        print("Yes")
    else:
        print("No")
elif t == 2:
    As = set(A)
    if len(A) != len(As):
        TF = True
    if TF:
        print("Contains duplicate")
    else:
        print("Unique")
elif t == 3:
    n = math.floor(N/2)
    y = -1
    p = 1
    for x in A:
        if y == -1:
            y = x
        elif y == x:
            p += 1
            if p > n:
                TF = True
                break
        else:
            y = x
            p = 1
    if TF:
        print(y)
    elif N < 2:
        print(A[0])
    else:
        print(-1)
        
elif t == 4:
    if N % 2 == 0:
        n1 = A[((N//2)-1)]
        n2 = A[(N//2)]
        print(n1, n2)
    elif N%2 == 1:
        n = (N-1)//2
        print(A[n])
        
elif t == 5:
    A2 = list(map(str, [x for x in A if x in range(100, 1000)]))
    print(*A2)