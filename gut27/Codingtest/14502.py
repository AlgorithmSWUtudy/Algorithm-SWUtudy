from itertools import combinations

n,m = map(int, input().split())
graph = []

for _ in n:
  graph.append(list(map(int, input().split())))

combi_result = combinations(graph,3)

def dfs(graph):
 
for a in combi_result:
  for i in range(3):
    x,y = a[i]
    if graph != 1:
      continue
    graph[x][y] = 1
  if !dfs(graph):
    for i in range(3):
      x,y = a[i]
      if graph != 1:
        continue
      graph[x][y] = 0
  else:
    result = min()

