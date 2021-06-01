# 범위 체크랑 어떤 위치에 뭐가 있는지는 한번에 확인 하면 안됨
# 변수 여러개 선언시 변수명 안섞이게 조심 또 조심!
# 연산자 우선순위!!!!!!!!!!!!!!!!!!!!!! 실수 ㄴㄴ

n = int(input())
arr = [[0]*n for _ in range(n)]
k = int(input())
for _ in range(k):
  x,y = map(int,input().split())
  arr[x-1][y-1] = -1
arr[0][0] = 1
arr_move = []
k = int(input())
for _ in range(k):
  arr_move.append(list(input().split()))
dx = [0,1,0,-1]
dy = [1,0,-1,0]
def dfs(i,j):
  dd = 0
  o = 0
  count = 0
  snake = [(0,0)]
  while True:
    nx = i+dx[dd]
    ny = j +dy[dd]
    count+=1
    if nx<0 or nx>= n or ny<0 or ny>=n:
      break
    if arr[nx][ny] == 1:
      break
    if arr[nx][ny] == -1:
      arr[nx][ny] = 1
      snake.append((nx,ny))
    else:
      arr[nx][ny] = 1
      t,a = snake[0]
      arr[t][a] = 0
      snake.pop(0)
      snake.append((nx,ny))
    i = nx
    j = ny
    if o < k and count == int(arr_move[o][0]):
      if arr_move[o][1] == 'D':
        dd = dd + 1 % 4
        print('D:',dd)
      else:
        dd = dd - 1 % 4
      print('dd:',dd)
      o += 1
  return count
print(dfs(0,0))
      
