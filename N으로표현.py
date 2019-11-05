def solution(N, number):
    from collections import defaultdict as dd
    dp = dd(lambda : 0)
    visited = [[]]
    number_1s = 1
    answer = -1
    for i in range(8):
        visited.append([number_1s * N])
        dp[number_1s* N] = i
        number_1s = 10 * number_1s + 1

    k = 1
    while(k < 8):
        for i in range(1,k+1):
            for num1 in visited[i]:
                for num2 in visited[k - i]:
                    if(num2 == 0):
                        continue
                    num_list = [num1 + num2, num1 - num2, num1 * num2, num1 // num2]

                    for candidate_num in num_list:
                        if not(dp[candidate_num]): # 여태 만들지 못했으면,
                            if(candidate_num == number):
                                answer = k
                                return answer
                            dp[candidate_num] = k
                            visited[k].append(candidate_num)
        k+=1
        print(visited[k])
    for num in visited[8]:
        if(num == number):
            answer = 8
            break

    return answer
