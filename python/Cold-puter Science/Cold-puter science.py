n = int(input())
temps = list(map(int, input().split()))
counter = 0

for x in temps:
	if x < 0:
		counter += 1

print(counter)