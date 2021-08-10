
from collections import deque

def dfs(i,computers,visited,n):
    
    q = deque([i])
    
    while q:
        a = q.popleft()
        for b in range(n):
            if computers[a][b] == 1 and visited[a][b] == 0:
                visited[a][b] = 1
                q.append(b)
    return True
                
def solution(n, computers):
    answer = 0
    visited = [[0]*n for _ in range(n)]
    count = 0
    
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0 and computers[i][j] != 0:
                visited[i][j] == 1
                if dfs(i,computers, visited,n):
                    count += 1
    answer = count
    
    return answer
