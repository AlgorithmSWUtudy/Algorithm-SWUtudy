# from copy import copy
from collections import deque
# n, m = map(int,input().split())
# arr= []
# for _ in range(n):
#   arr.append(list(map(int,input().split())))
n = 7
m = 3
arr= [[2, 0, 0, 0, 1, 1, 0], [0, 0, 1, 0, 1, 2, 0], [0, 1, 1, 0, 1, 0, 0], [0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 2, 0, 1, 1], [0, 1, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0]]
arr_temp = [[0]*n for _ in range(n)]
print(arr)
dx=[0,0,1,-1]
dy = [1,-1,0,0]
global time
time = 0
global answer
answer= 1e9

#bfs를 활용하여
def virus(x,y):  
  t= 0
  queue = deque()
  queue.append((x,y))
  while queue:  # 바이러스를 퍼뜨리는 작업
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= nx < n and 0 <= ny < n:
        if arr_temp[nx][ny] == '-':
          continue
        if arr_temp[nx][ny] == -1:
          queue.append((nx, ny))
          if arr_temp[x][y] == -2 or arr_temp[x][y] == -1:
            arr_temp[nx][ny] = 1
          else:
            arr_temp[nx][ny] = arr_temp[x][y] + 1
          t = arr_temp[nx][ny]
        elif arr_temp[nx][ny] >= 0:
          queue.append((nx, ny))
          if arr_temp[x][y] == -2:
            arr_temp[nx][ny] = 1
          else:
            arr_temp[nx][ny] = arr_temp[x][y] + 1          
          t = arr_temp[nx][ny]  
  return t
def dfs(count):
  global answer
  global time
  # 활성화 개수가 m이면
  if count == m:
    for i in range(n):
      for j in range(n):
        # 비활성화 바이러스
        if arr[i][j] == 2:
          arr_temp[i][j] = -1
        # 벽
        elif arr[i][j] == 1:
          arr_temp[i][j] = '-'
        else:
          arr_temp[i][j] = arr[i][j]

    # 바이러스 퍼트리기
    for i in range(n):
      for j in range(n):
        if arr[i][j] == -2:
          time = max(time,virus(i,j))
    print(arr_temp, time)
    answer = min(time,answer)

# 바이러스 활성화
  for i in range(n):
    for j in range(n):
      if arr[i][j] == 2:
        count += 1
        arr[i][j] = -2
        dfs(count)
        count -= 1
        arr[i][j] = 2
      
dfs(0)
print(answer)
