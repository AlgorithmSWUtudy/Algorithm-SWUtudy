n = int(input())
arr = []
for i in range(n):
  arr.append(list(map(int,input().split())))
fish_num = 0
for i in range(n):
  for j in range(n):
    if arr[i][j] == 9:
      x = i
      y = j
    if arr[i][j] != 9 and arr[i][j] != 0:
      fish_num+=1
shark_size = [2,0]
answ = 0
count = 0
fish_visited = 0
def bfs(x,y,arr, shark_size,fish_visited,count):
  global answ
  if x<0 or x>= n or y<0 or y>= n:
    answ = max(answ, count)
    return 
  if fish_num == fish_visited:
    answ = max(answ, count)
    return 
  count +=1
  if arr[x][y] != 0 and arr[x][y] != 9:
    if arr[x][y] > shark_size[0]:
      return
    if arr[x][y] < shark_size[0]:
      shark_size[1] += 1
      if shark_size[1] >= shark_size[0]:
        shark_size[0] += 1
        shark_size[1] = 0
        arr[x][y] = 0
    fish_visited += 1
  bfs(x-1,y,arr, shark_size,fish_visited,count)
  bfs(x,y-1,arr, shark_size,fish_visited,count)
  bfs(x+1,y,arr, shark_size,fish_visited,count)
  bfs(x,y+1,arr, shark_size,fish_visited,count)
  
bfs(x,y,arr, shark_size,fish_visited,count)
print(answ)
