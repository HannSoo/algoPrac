def solution(prices):
    import bisect
    len_prices = len(prices)
    answer =  [len_prices - i -1  for i in range(0,len_prices)]

    price_i = [] # increasingly
    price_p = [] # increasingly

    for i, p in enumerate(prices):
        index = bisect.bisect_right(price_p,p)
        print(price_i)

        for index in price_i[index:]:
            answer[index] = i - index
        price_p = price_p[:index]
        price_i = price_i[:index]
        price_p.append(p)
        price_i.append(i)

    return answer
