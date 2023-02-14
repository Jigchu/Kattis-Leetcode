# Actual code
while True:
        try:
                len, rm = list(map(int, input().split()))
                rand_arr = list(map(int, input().split()))
                occurrence = {}

                # Gets occurence of every val
                for x in rand_arr:
                        if not occurrence.get(x):
                                occurrence[x] = 1
                        else:
                                occurrence[x] += 1

                # Gets a sorted list based on times appeared
                occurrence_list = sorted(occurrence.items(), key=lambda x : x[1], reverse=True)
                
                index = 1

                # Gets first and second
                highest = occurrence_list[index - 1][1]
                second = occurrence_list[index][1]

                # Min maxes occurrence
                while rm > 0:
                        # Removes one from the highest
                        highest -= 1
                        rm -= 1

                        # Checks if second is higher
                        if second > highest:
                                # Replaces higher with second
                                highest = second
                                occurrence_list = sorted(occurrence.items(), key=lambda x : x[1], reverse=True)
                                second = occurrence_list[index][1]
                        

                print(highest)

        except Exception:
                break