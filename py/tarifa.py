# Gets var and input
data_m = int(input())
month = int(input())

used = []

left = data_m

for _ in range(month):
    temp = int(input())
    used.append(temp)

# Gets answer
for data in used:
    left -= data
    left += data_m
    
print(left)