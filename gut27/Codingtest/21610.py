import copy

n, m = map(int, input().split())
arr = []
result = 0
for _ in range(n):
  arr.append(list(map(int,input().split())))
arr_move = []
for _ in range(m):
  arr_move.append(map(int,input().split()))
arr_cloud = [(n-1, 0),(n-1, 1),(n-2, 0),(n-2, 1)]
d = [(0,0),(0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1)]
d2 = [(-1,-1),(-1,1),(1,-1),(1,1)]
for i, num in arr_move:
  temp = []
  for x,y in arr_cloud:
    x= (x+(d[i][0]*num)) % n
    y= (y+(d[i][1]*num)) % n
    arr[x][y] += 1
    temp.append((x,y))
  arr_cloud = copy.deepcopy(temp)
  for x,y in arr_cloud:
    count = 0
    for i,j in d2:
      nx = x + i
      ny = y + j
      if nx<0 or nx>= n or ny<0 or ny>= n:
        continue
      if arr[nx][ny] >= 1:
        count += 1
    arr[x][y] += count
  temp = []

  for x in range(n):
    for y in range(n):
      if (x,y) in arr_cloud:
        continue
      if arr[x][y] >= 2:
        arr[x][y] -= 2
        temp.append((x,y))
  arr_cloud = copy.deepcopy(temp)


for x in range(n):
  for y in range(n):
    if arr[x][y] != 0:
      result += arr[x][y]
print(result)
