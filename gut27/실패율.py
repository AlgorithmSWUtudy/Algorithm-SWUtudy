N = int(input())
stages = list(map(int,input().split()))
data = []
t = 0
for i in range(1, N+1):
  j = stages.count(i)
  m = len(stages) - t
  data.append((j//m, i))
  t += j
  j = 0

data.sort(key=lambda x:(-x[0], x[1]))

for i in range(N):
  print(data[i][1])
  #######

def solution(N,stages):
  answer = []
  length = len(stages)

  for i in range(1,N+1):
    count = stage.count(i)

    if length == 0:
      fail = 0
    else:
      fail = count/length
    
    answer.append((i,fail))
    length -= count

answer = sorted(answer, key=lambda t: t[1], reverse = True)

answer = [i[0] for i in answer]
return answer
