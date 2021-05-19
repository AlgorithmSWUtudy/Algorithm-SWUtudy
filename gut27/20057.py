# 실패
n = int(input())
arr = []
answer = 0
for _ in range(n):
  arr.append(list(map(int,input().split())))
r = (n-1)//2
c = (n-1)//2
j = 0
x = 0
dr = [0,1,0,-1]
dc = [-1,0,1,0]
num = [[0.02,-2,0],[0.1,-1,-1],[0.07,-1,0],[0.01,-1,1],[0.05,0,-2],[0.1,1,-1],[0.07,1,0],[0.01,1,1],[0.02,2,0],[0.02,0,-1],[0.1,1,-1],[0.07,0,-1],[0.01,-1,-1],[0.05,-2,0],[0.1,1,1],[0.07,0,1],[0.01,-1,1],[0.02,0,-2],[0.02,-2,0],[0.1,-1,-1],[0.07,-1,0],[0.01,-1,1],[0.05,0,2],[0.1,1,-1],[0.07,1,0],[0.01,1,1],[0.02,2,0],[0.02,0,-1],[0.1,1,-1],[0.07,0,-1],[0.01,-1,-1],[0.05,-2,0],[0.1,1,1],[0.07,0,1],[0.01,-1,1],[0.02,-2,-0]]
while j < n:
  for _ in range(2):
    for i in range(j, j+1):
      x = x % 4
      nr = r + dr[x]
      nc = c + dc[x]
      if nr < 0 or nr >=n or nc<0 or nc>=n:
        continue
      for k in range(x*9,x*9+9):
        p,q,w = num[k]
        nnr = r+q
        nnc = c+w
        if nnr < 0 or nnr >=n or nnc<0 or nnc>=n:
          continue
        arr[nnr][nnc] = arr[nnr][nnc] + arr[r][c]*p
        arr[r][c] -= arr[r][c]*p
      arr[nr][nc] = arr[nr][nc] + arr[r][c]
      x += 1

for i in range(0, n-1):
  x = x % 4
  nr = r + dr[x]
  nc = c + dc[x]
  if nr < 0 or nr >=n or nc<0 or nc>=n:
    continue
  for k in range(x*9,x*9+9):
    p,q,w = num[k]
    nnr = r+q
    nnc = c+w
    if nnr < 0 or nnr >=n or nnc<0 or nnc>=n:
      continue
    arr[nnr][nnc] = arr[nnr][nnc] + arr[r][c]*p
    arr[r][c] -= arr[r][c]*p
  arr[nr][nc] = arr[nr][nc] + arr[r][c]
  
for i in range(0, 1):
  x = x % 4
  nr = r + dr[x]
  nc = c + dc[x]
  for k in range(x*9,x*9+9):
    p,q,w = num[k]
    nnr = r+q
    nnc = c+w
    if nnr < 0 or nnr >=n or nnc<0 or nnc>=n:
      answer += arr[r][c]*p
    arr[nnr][nnc] = arr[nnr][nnc] + arr[r][c]*p
    arr[r][c] -= arr[r][c]*p
  answer += arr[r][c]

print(int(answer))
