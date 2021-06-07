def solution(n, results):
    answer = 0
    INF = 1e9
    graph = [[INF]*n for _ in range(n)]
    rank = [INF]*n
    for i in range(n):
        graph[i][i] = 0
    for x,y in results:
        graph[x-1][y-1] = 1
        graph[y-1][x-1] = -1
    
    for j in range(n):
        count = 0
        minus = 0
        for i in range(n):
            if graph[j][i] != INF:
                count+= 1
            if graph[i][j] == -1:
                minus += -1
        if count == n:
            rank[j] = n+minus
    for i in range(n):
        temp = []
        if rank[i] != INF:
            if rank[i] == 2:
                for j in range(n):
                    if graph[i][j] == -1:
                        temp.append((j))
                if len(temp) == 1:
                    rank[temp[0]] = 1
            if rank[i] == n-1:
                for j in range(n):
                    if graph[i][j] == 1:
                        temp.append((j))
                if len(temp) == 1:
                    rank[temp[0]] = n
    for i in range(n):
        if rank[i] != INF:
            answer+=1
    return answer
