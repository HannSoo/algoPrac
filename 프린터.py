
def solution(priorities, location):

    def get_last_point(priorities,last_point,number):
        num_p = len(priorities)
        for i in range(1,last_point+1):
            from_last_point_to_begin = last_point - i
            if(priorities[from_last_point_to_begin]  == number):
                return from_last_point_to_begin
        for j in range(0, num_p - last_point):
            from_end_to_last_point = num_p - j - 1
            if(priorities[from_end_to_last_point] == number):
                return from_end_to_last_point

        return last_point


    num_p = len(priorities)
    tg_p = priorities[location]
    gl_p = 10 # 최대 값으로 초기화
    g_p = 0
    s_p = 0

    last_point = 0
    for i in range(10-tg_p):
        prior = 10 - i
        last_point = get_last_point(priorities,last_point,prior)

    for i in range(num_p):
        p = priorities[i]
        if( p > tg_p):
            g_p += 1

    if(last_point < location):
        for i in range(last_point,location+1):
            p = priorities[i]
            if(p == tg_p):
                s_p += 1
    else:
        for i in range(0,location+1):
            p = priorities[i]
            if(p == tg_p):
                s_p += 1
        for i in range(last_point,num_p):
            p = priorities[i]
            if(p == tg_p):
                s_p += 1
    answer = s_p + g_p

    return answer
