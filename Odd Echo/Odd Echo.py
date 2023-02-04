N = int(input())
words = []
echo = []

for _ in range(0, N):
	new_val = input()
	words.append(new_val)

for idx, val in enumerate(words):
	if idx%2 == 0:
		echo.append(val)

for x in echo:
	print(x)