# Gets number of test cases
test = int(input())

# Main
for _ in range(test):
    # Gets input and vars
    outlets = list(map(int, input().split()))
    out_num = outlets[0]
    outlets = outlets[1:]
    total_soc = 0

    # Total socket count
    for outlet in outlets:
        total_soc += outlet

    # Usable sockets
    total_soc -= (out_num - 1)

    # Return answer
    print(total_soc)