#다시풀기
r,c,t = map(int, input().split())
graph = []
arr_cleaner = []
for i in range(r):
  a = list(map(int, input().split()))
  if -1 in a:
    air_cleaner = [(i,0),(i+1,0)]
  graph.append(a)
time = 0

def air_moev(ar,ac):
  temp_graph = [[0]*c for _ in range(r)]
  dar = [0,-1,0,1]
  dac = [1,0,-1,0] 
  flag = 0
  ar2= ar
  ac2 = ac
  ac = ac + 1
  while flag<4:
    nar = ar +dar[flag]
    nac = ac + dac[flag] 
    if nar <0 or nar >= r or nac<0 or nar >= c:
      flag += 1
      continue
    if graph[nar][nac] == -1:
      break
    temp_graph[nar][nac] = graph[ar][ac]
    ar = nar
    ac = nac 
  while flag<4:
    nar = ar2 +dar[flag]
    nac = ac2 + dac[flag] 
    if nar <0 or nar >= r or nac<0 or nar >= c:
      flag += 1
      continue
    graph[nar][nac] = graph[nar][nac]
    if graph[nar][nac] == -1:
      break
    ar = nar
    ac = nac
  return temp_graph
def air_moev2(ar,ac):
  dar = [0,-1,0,1]
  dac = [1,0,-1,0]
  temp_graph = [[0]*c for _ in range(r)]
  flag = 0
  ac2 = ac
  ac = ac + 1
  ar2 = ar
  while flag<4:
    nar = ar +dar[flag]
    nac = ac + dac[flag] 
    if nar <0 or nar >= r or nac<0 or nar >= c:
      flag += 1
      continue
    if graph[nar][nac] == -1:
      break
    temp_graph[nar][nac] = graph[ar][ac]
    ar = nar
    ac = nac 
  while flag<4:
    nar = ar2 +dar[flag]
    nac = ac2 + dac[flag] 
    if nar <0 or nar >= r or nac<0 or nar >= c:
      flag += 1
      continue
    graph[nar][nac] = graph[nar][nac]
    if graph[nar][nac] == -1:
      break
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
        if ni < 0 or ni >= r or nj <0 or nj >= c:
          continue
        temp_graph[ni][nj] = graph[i][j]//5
        count+=1
      graph[i][j] = graph[i][j] - ((graph[i][j]//5)*count)
  print(graph,temp_graph)
  for i in range(r):
    for j in range(c):
      graph[i][j] = graph[i][j] + temp_graph[i][j]
  print('honono')
  print(graph)

  down_ar = air_cleaner[1][0]
  down_ac = air_cleaner[1][1]
  air_moev(air_cleaner[0][0],air_cleaner[0][1])
  air_moev2(air_cleaner[0][0],air_cleaner[0][1])
  time += 1
  print('time',time)
  print(graph)
result = 0
for i in range(i):
  for j in range(j):
    if graph[i][j] == -1:
      continue
    result += graph[i][j]

print(result)
