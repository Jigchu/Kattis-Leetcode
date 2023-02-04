while True:
    prices = input().split()
    prices = list(map(int, prices))
    import random
    if len(prices) <= 1:
        print (0)
    highest_profit = -1
    answers = []
    max_list_len = (len(prices)**2 + len(prices))//2
    while len(answers) < max_list_len:
        Low = random.randint(0, len(prices) - 2)
        High = 0
        while Low >= High:
            High = random.randint(0, len(prices) - 1)
        answers.append(prices[High] - prices[Low])
    for x in answers:
        if highest_profit < x:
            highest_profit = x
    if highest_profit == -1:
        print(0)
    print(highest_profit)