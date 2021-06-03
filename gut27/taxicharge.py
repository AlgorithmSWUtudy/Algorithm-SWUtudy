def solution(n, s, a, b, fares):
    answer = 0
    INF = 1e9
    arr= [[0]*(n+1) for _ in range(n+1)] 
    for x,y,i in fares:
        arr[x][y] = i
        arr[i][x] = i
    for i in range(1,n+1):
        arr[i][i] = 0
        
    for t in range(n):
        for i in range(n):
            for j in range(i, n):                   
                if i != j:                          #최소 비용 계산
                    temp = min(graph[i][j], graph[i][t] + graph[t][j]) 
                    graph[i][j] = graph[j][i] = temp

    answer = INF
    for t in range(n):                              #경유점에 따라 최소 합승 비용 탐색
        temp = graph[s - 1][t] + graph[t][b - 1] + graph[t][a - 1]      
        answer = min(answer, temp)
    
    return answer
