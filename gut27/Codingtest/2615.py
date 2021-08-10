graph = [list(map(int, input().split())) for _ in range(19)]

def a(i,j):
  tj = j
  for _ in range(4):
    tj = tj+1
    if tj >=19:
      return False
    if graph[i][j] != graph[i][tj]:
      return False
  return True

def b(i,j):
  ti = i
  for _ in range(4):
    ti = ti+1
    if ti >=19:
      return False
    if graph[i][j] != graph[ti][j]:
      return False
  return True

def c(i,j):
  ti = i
  tj = j
  for _ in range(4):
    ti = ti+1
    tj = tj+1
    if ti >=19 or tj >=19:
      return False
    if graph[i][j] != graph[ti][tj]:
      return False
  return True

def d(i,j):
  ti = i
  tj = j
  for _ in range(4):
    ti = ti + 1
    tj = tj-1
    if ti >= 0 or tj <0:
      return False
    if graph[i][j] != graph[ti][tj]:
      return False
  return True

result = False
for i in range(19):
  for j in range(19):
    if graph[i][j] == 0:
      continue
    if a(i,j) or b(i,j) or c(i,j) or d(i,j):
      print(str(graph[i][j])+"\n"+str(i+1)+" "+str(j+1))
      result = True
      break
  if result == True:
    break
