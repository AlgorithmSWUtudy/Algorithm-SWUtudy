# r,c,t = map(int, input().split())
# graph = []
# air_cleaner = []
# for i in range(r):
#   a = list(map(int, input().split()))
#   if -1 in a:
#     air_cleaner.append((i,0))
#   graph.append(a)
r = 7
c = 8
t = 3
graph = [[0, 0, 0, 0, 0, 0, 0, 9], [0, 0, 0, 0, 3, 0, 0, 8], [-1, 0, 5, 0, 0, 0, 22, 0], [-1, 8, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 10, 43, 0], [0, 0, 5, 0, 15, 0, 0, 0], [0, 0, 40, 0, 0, 0, 20, 0]]
air_cleaner = [(2, 0), (3, 0)]
print(5//5)
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
    print('ar')
    print(ar,ac)
    nar = ar +dar[flag]
    nac = ac + dac[flag] 
    print('')
    print(nar,nac)
    if nar <0 or nar >= r or nac<0 or nac >= c:
      flag += 1
      continue
    if graph[nar][nac] == -1:
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
      if (time == 1):
      graph[i][j] = graph[i][j] - ((graph[i][j]//5)*count)
  for i in range(r):
    for j in range(c):
      graph[i][j] = graph[i][j] + temp_graph[i][j]
  print('hono1',graph)
  air_move(air_cleaner[0][0],air_cleaner[0][1])
  print('hono2',graph)
  air_move2(air_cleaner[1][0],air_cleaner[1][1])
  print('hono3',graph)
  time += 1

result = 0
for i in range(r):
  for j in range(c):
    if graph[i][j] == -1 or graph[i][j] == 0:
      continue
    result += graph[i][j]

print(result)
