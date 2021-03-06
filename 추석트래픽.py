'''
https://programmers.co.kr/learn/courses/30/lessons/17676?language=python3
180828

while 문 수정 바람.
while문 조건문을 if문으로 바꾸고,
(해당 조건은 검사하는 line 수를 줄이기 위함일 뿐, maxTraffic을 증가시키는 조건이 아님.)

해당 조건 안에서는,
모든 start 시간마다 count해줘야한다.
'''

def solution(lines):

    #get input
    S , E= [], []
    totalLines = 0
    for line in lines:
        totalLines += 1
        type(line)
        (d,s,t) = line.split(" ")

       ##time to float
        t = float(t[0:-1])
        (hh, mm, ss) = s.split(":")
        seconds = float(hh) * 3600 + float(mm) * 60 + float(ss)

        E.append(seconds)
        S.append(seconds - t + 0.001)

    #count the maxTraffic
    index = 0
    maxTraffic = 0
    end = 0
    for time in S:
        if(index + maxTraffic == totalLines):
            end = 1
            break
        while(E[index] + 1 >  S[index + maxTraffic]):
            maxTraffic += 1
            if(index + maxTraffic == totalLines):
                end = 1
                break

        if(end): break
        else:
            index += 1

    return maxTraffic
