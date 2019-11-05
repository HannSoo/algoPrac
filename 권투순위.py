def solution(n,results):
    # # of players
    # results : [[lose,win], ...]

    visited = [ False for _ in range(n)]
    adj = [[0 for _ in range(n)] for _ in range(n)]

    def makeAdj(results):
        for loser,winner in results:
            winner -= 1
            loser -= 1
            adj[winner][loser] = 1
            adj[loser][winner] = -1

    makeAdj(results)


    # here를 이긴자들.

    def dfs(here,winners,adj):
        for there in range(n):
            if(adj[here][there] == -1):
                winners.append(there)


        if(winners):
            for winner in winners:

                adj[here][winner] = -1
                adj[winner][here] = 1

        winners = []
        winners.append(here)
        visited[here] = True
        for there in range(n):
            if(adj[here][there] == 1 & visited[there] == False):
                dfs(there, winners,adj)




    def dfsAll():
        for i in range(n):
            if not(visited[i]):
                dfs(i,[],adj)

    dfsAll()

    def count_ranked():
        ranked = 0
        for player in range(n):
            round = 0
            for opponent in range(n):
                if(adj[player][opponent] != 0):
                    round += 1

            if(round == n- 2):

                ranked += 1
        return ranked


    return count_ranked()
