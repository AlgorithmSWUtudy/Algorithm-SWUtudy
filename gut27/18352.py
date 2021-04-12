from collections import deque

n,m,k,x = map(int, input().split())
graph = [[0]*n for _ in range(n)]

for _ in m:
  x,y = map(int, input().split())
  graph[x].append(y)

visited = [[0]*n]

def bfs(k):
  result = 0
  queue = deque()
  queue.append(k,graph[k])
  while queue:
    x,y = queue.popleft()
    for i in y:
      visited[i] = visited[x] + 1
      if visited[i] == 2:
        result += 1
      else:
        queue.append(i,graph[i])  
    return result

print(bfs(k))
