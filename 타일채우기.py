def solution(n):

    T = [-1 for _ in range(n)]
    def tiling(n):
        if(n < 3):
            return n
        if (T[n] == -1):
            T[n] = tiling(n -1) + tiling(n-2)

        return T[n]

return tiling(n)

solution(92)
