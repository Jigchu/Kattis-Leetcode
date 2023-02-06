# Sets all vals for question
x = int(input())
y = int(input())

x_neg = False
y_neg = False

quad = 1

# Checks if x and/or y is negative
if (x < 0):
    x_neg = True

if (y < 0):
    y_neg = True

# Assigns quad sect
if (x_neg and not y_neg):
    quad = 2
elif (y_neg and not x_neg):
    quad = 4
elif (x_neg and y_neg):
    quad = 3

print(quad)