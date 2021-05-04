import heapq
INF = int(1e9)
city = 0
result = 0
n, m, c = map(int, input().split())
start = c
graph = [[] for i in range(n+1)]
distance = [INF]*(n+1)
for _ in range(m):
  x,y,z = map(int, input().split())
  graph[x].append((y,z))

def dijkstra(start):
  q = []
  heapq.heappush(q,(0,start))
  distance[start] = 0
  while q:
    dist, now = heapq.heappop(q)

    if distance[now] < dist:
      continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
    for i in graph[now]:
      cost = dist + i[1]
      # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q, (cost, i[0]))

# 다익스트라 알고리즘을 수행
dijkstra(start)

# 모든 노드로 가기 위한 최단 거리를 출력
for i in range(1, n + 1):
    # 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
  if distance[i] == INF:
    continue
    # 도달할 수 있는 경우 거리를 출력
  else:
    city += 1
    result = max(distance[i],result)
print(city-1, result)
