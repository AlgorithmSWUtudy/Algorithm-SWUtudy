# PyPy3에서 돌아간다. 파이썬은 시간초과

r,c,t = map(int, input().split())
graph = []
air_cleaner = []
for i in range(r):
  a = list(map(int, input().split()))
  if -1 in a:
    air_cleaner.append((i,0))
  graph.append(a)
time = 0
def air_move(ar,ac):
  dar = [0,-1,0,1]
  dac = [1,0,-1,0] 
  temp = [0]
  flag = 0
  ac = ac + 1
  while flag<=4:
    nar = ar +dar[flag]
    nac = ac + dac[flag] 
    if nar <0 or nar >= r or nac<0 or nac >= c:
      flag += 1
      continue
    if graph[nar][nac] == -1:
      graph[ar][ac] = temp[0]
      temp.pop(0)
      break
    temp.append(graph[ar][ac])
    graph[ar][ac] = temp[0]
    temp.pop(0)
    ar = nar
    ac = nac 

def air_move2(ar,ac):
  dar = [0,1,0,-1]
  dac = [1,0,-1,0]
  temp = [0]
  flag = 0
  ac = ac + 1
  while flag<=4:
    nar = ar +dar[flag]
    nac = ac + dac[flag] 
    if nar <0 or nar >= r or nac<0 or nac >= c:
      flag += 1
      continue
    if graph[nar][nac] == -1:
      graph[ar][ac] = temp[0]
      temp.pop(0)
      break
    temp.append(graph[ar][ac])
    graph[ar][ac] = temp[0]
    temp.pop(0)
    ar = nar
    ac = nac 

di = [0,0,-1,1]
dj = [1,-1,0,0]
while time < t:
  temp_graph = [[0]*c for _ in range(r)]
  for i in range(r):
    for j in range(c):
      if graph[i][j] == 0 or graph[i][j] == -1:
        continue
      count = 0
      for z in range(4):
        ni = i + di[z]
        nj = j + dj[z]
        if ni < 0 or ni >= r or nj <0 or nj >= c or graph[ni][nj] == -1:
          continue
        temp_graph[ni][nj] = temp_graph[ni][nj] + graph[i][j]//5
        count+=1
      graph[i][j] = graph[i][j] - ((graph[i][j]//5)*count)
  for i in range(r):
    for j in range(c):
      graph[i][j] = graph[i][j] + temp_graph[i][j]
  air_move(air_cleaner[0][0],air_cleaner[0][1])
  air_move2(air_cleaner[1][0],air_cleaner[1][1])
  time += 1

result = 0
for i in range(r):
  for j in range(c):
    if graph[i][j] == -1 or graph[i][j] == 0:
      continue
    result += graph[i][j]

print(result)
