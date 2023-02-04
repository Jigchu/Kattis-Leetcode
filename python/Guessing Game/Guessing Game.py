N = []
V = []
R = []
I = 0

while True:
    n = int(input())
    if n == 0:
        break
    v = input()
    R.append(n)
    R.append(v)

for j in R:
    if j == "right on":
        J = R.index(j)
        R2 = R[I:J+1]
        I = J
        R.remove(j)
        V = [x for x in R2 if type(x)==str]
        N = [x for x in R2 if type(x)==int]
        P = list(range(1, 11))
        for index, verdict in enumerate(V):
            number = N[index]
            if verdict == 'too low':
                P = [x for x in P if x > number]
            elif verdict == 'too high':
                P = [x for x in P if x < number]
            if len(P) == 0:
                honesty = False
                break
            elif len(P) != 0:
                honesty = True
        if honesty == True:
            print("Stan may be honest")
        elif honesty == False:
            print("Stan is dishonest")