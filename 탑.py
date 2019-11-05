    def solution(heights):
        import bisect
        answer = []
        num_tower = len(heights)
        tower_h = [0]
        tower_i = [0]
        MAX_HEIGHT = 100

        for i in range(num_tower):
            height = heights[i]
            index = bisect.bisect_right(tower_h,MAX_HEIGHT - height)
            print(tower_h)
            answer.append(tower_i[index-1])
            tower_i = tower_i[:index]
            tower_h = tower_h[:index]
            tower_i.append(i+1)
            tower_h.append(MAX_HEIGHT - height)

        return answer
