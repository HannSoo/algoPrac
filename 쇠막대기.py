def solution(arrangement):
    answer = 0
    sticks = 0
    pChar = ''
    for char in arrangement:
        if(char == ')'):
            if(pChar == '('):
                # laser fire
                answer += sticks
            else:
                sticks -= 1
                answer += 1
                # sticks decrease
        elif(char == '('):
            if(pChar == '('):
                # sticks increase
                sticks += 1


        pChar = char


    return answer
