#다시풀기
n = int(input())
arr = []
for _ in range(n):
  arr.append(list(map(int,input().split())))
visited=[[0]*n for _ in range(n)]
global result
result = 0
def find(x,y):
  dx=[-1,-1,1,1]
  dy=[-1,1,-1,1]
  flag = 0
  tx = x
  ty = y
  while flag < 4:
    nx = tx + dx[flag]
    ny = ty+dy[flag]
    if nx <0 or nx >= n or ny < 0 or ny>=n:
      flag += 1
      tx = x
      ty = y
      continue
    if arr[nx][ny] == 2:
      return False
    tx = nx
    ty = ny
  arr[x][y] = 2
  return True

def put_chess(count,visited):
  global result
  for i in range(n):
    for j in range(n):
      if arr[i][j] == 1 and not visited[i][j]:
        if find(i,j):
          count +=1
          visited[i][j] = 1
          result = max(result,put_chess(count,visited))
          visited[i][j] = 0
  return count
put_chess(0,visited)

# result = 0
# for i in range(n):
#   for j in range(n):
#     if arr[i][j] == 2:
#       result+=1
      
print(result)
