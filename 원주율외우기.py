"""

"""

def memo_all(number):

    def dfc(word):
        #숫자가 같을때                             1
        # 숫자가 1씩 단조 증가하거나 단조 감소할때       2
        # 두개의 숫자가 번갈아가며 나타날때            4
        # 숫자가 등차수열을 이룰 때 d != 1             5
        # 이 외의 모든 경우                          10

        case1 = case2 = case3= case4= case5 =True
        
        for i in range(len(word)):
            if(word[0] != word[i] & case1):
                case1 = False
            if(i != 0):
                if(word[i-1] )


    def memo(index):
