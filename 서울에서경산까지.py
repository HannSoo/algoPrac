def solution(K, travel):

    '''
    i번째 도시에서 limit_time 내로 가장 많이 모은 모금액을 fund(i,limit_time)라하자.
    fund(i,limit_time) =
    max(fund(i-1,limit_time - Tb[i])
    + Mb[i],fund(i-1,limit_time - Tw[i]) + Mw[i])
    '''
    Tb, Mb, Tw, Mw = [], [], [], []
    numTowns = len(travel)
    for t_w, m_w, t_b, m_b in travel:
        Tw.append(t_w)
        Mb.append(m_b)
        Mw.append(m_w)
        Tb.append(t_b)

    NEVER = -2
    NOWAY = -1
    from collections import defaultdict as dd
    funds = [dd(lambda : NEVER) for i in range(0,numTowns)] # save as fund[town_index][time_limit] = money
    def fund(i, limit_time):

        """
            fund(i-1,limit_time - Tb[i-1]) 이 값이 저장되어있으면 바로 불러오도록 해야한다.
            그리고 항상 저장되어있어야한다.
            fund i를 limit_time 별로 구분해놔야함.
            limit_times = [lt1, lt2, lt3... lti, lt(i+1)]이 있다.
            현재 limit_time이 lti~lt(i+1)의 구간에 속하면,
            funds = [0,fd1,... fdi,fdi(i+1)]에 넣어야함.

            또한 해당 fund(i-1,limit_time - Tb[i-1]) 값이 -1이면
            역시 timelist 에 append하면 안 된다.
            """
        if(limit_time <0):

            return NOWAY

        if(i == 0):
            return 0

        timelist = []

        if(funds[i-1][limit_time - Tb[i-1]] == NEVER):#fund(i-1,limit_time - Tb[i-1])이 값이 있었는지 판별
            funds[i-1][limit_time - Tb[i-1]] = fund(i-1,limit_time - Tb[i-1])
        wayBike = funds[i-1][limit_time - Tb[i-1]]
        if(wayBike != NOWAY):
            timelist.append(wayBike + Mb[i-1])

        if(funds[i-1][limit_time - Tw[i-1]] == NEVER):#fund(i-1,limit_time - Tw[i-1])이 값이 있었는지 판별
            funds[i-1][limit_time - Tw[i-1]] = fund(i-1,limit_time - Tw[i-1])
        wayWalk = funds[i-1][limit_time - Tw[i-1]]
        if(wayWalk != NOWAY):
            timelist.append(wayWalk + Mw[i-1])

        if(timelist):
            answer= max(timelist)
            return answer
        else:
            return -1


    answer = fund(numTowns,K)


    return answer
