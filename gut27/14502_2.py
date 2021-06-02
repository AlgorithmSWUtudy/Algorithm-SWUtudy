from collections import deque
n, m = map(int,input().split())
arr= []
for _ in range(n):
  arr.append(list(map(int,input().split())))

dx=[0,0,1,-1]
dy = [1,-1,0,0]

def safetyzone(arr_new):
  count = 0
  for i in range(n):
    for j in range(m):
      if arr_new[i][j] == 0:
        count +=1
  return count

def virus(arr_new):
  queue = deque()
  for i in range(n):
    for j in range(m):
      if arr_new[i][j] == 2:
        queue.append((i,j))
  while queue:
    x,y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx<0 or nx>=n or ny<0 or ny >= m:
        continue
      if arr_new[nx][ny] == 1:
        continue
      if arr_new[nx][ny] == 0:
        arr_new[nx][ny] = 2
        queue.append((nx,ny))
  return safetyzone(arr_new)

def dfs(count):
  result = 0
  for i in range(n):
    for j in range(m):
      if arr[i][j] == 0:
        count += 1
        arr[i][j] = 1
      if count < 3:
        dfs(count)
      if count == 3:
        result = max(result,virus(arr))
      count -= 1
      arr[i][j] = 0
      
print(dfs(0))
