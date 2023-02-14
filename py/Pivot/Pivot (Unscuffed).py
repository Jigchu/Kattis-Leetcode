N = int(input())
L = input().split()
L = [int(x) for x in L]
x = -1
n = 100001
B = []
S = []
R = 0

for z in L:
    if z >= x:
        x = z
        B.append(True)
    else:
        B.append(False)

L.reverse()

for z in L:
    if z < n:
        n = z
        S.append(True)
    else:
        S.append(False)

B.reverse()

for z in range(N):
    if B[z] and S[z]:
        R += 1

print(R)