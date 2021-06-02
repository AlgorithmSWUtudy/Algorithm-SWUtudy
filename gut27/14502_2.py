# from copy import copy

n, m = map(int,input().split())
arr= []
for _ in range(n):
  arr.append(list(map(int,input().split())))
arr_temp = [[0]*m for _ in range(n)]
dx=[0,0,1,-1]
dy = [1,-1,0,0]
result = 0
def safetyzone():
  count = 0
  for i in range(n):
    for j in range(m):
      if arr_temp[i][j] == 0:
        count +=1
  return count

def virus(x,y):  
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if arr_temp[nx][ny] == 0:
      arr_temp[nx][ny] = 2

def dfs(count):
  global result
  if count == 3:
    for i in range(n):
      for j in range(m):
        arr_temp[i][j] = arr[i][j]
    for i in range(n):
      for j in range(m):
        if arr[i][j] == 2:
          virus(i,j)
    result = max(result,safetyzone())
    return
  for i in range(n):
    for j in range(m):
      if arr[i][j] == 0:
        count += 1
        arr[i][j] = 1
        dfs(count)
        count -= 1
        arr[i][j] = 0
      
print(dfs(0))
