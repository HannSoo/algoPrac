def generate(n, m, prevString):
    if(n == 0 & m == 0):
        print(prevString)
        return
    else:
        if(n > 0):
            generate(n-1,m,prevString + "-")
        if(m > 0):
            generate(n,m-1,prevString + "o")
