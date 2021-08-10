s = list(input())
answer = 0
visited = ['false']*len(s)

# 들어온 문장의 길이가 5로 나누어 떨어지지 않으면 틀린것
# 이걸 잡지 않으면 통과하지 못함, 아마도 우연히 aquack이 되는 경우가 있나보다.
if len(s) % 5 != 0:
   print(-1)
   # 메인에서 종료시 이걸 쓴다. 백준은
   exit()

def check(num):
  duck = ['q','u','a','c','k']
  che = 0
  i = 0
  # 비교 후 방문 처리, 인덱스를 1씩 올려가며
  for n in range(num,len(s)):
    if visited[n] == 'false' and s[n] == duck[i]: 
      visited[n] = 'true'
      i = (i+1)%5
      if i == 0:
        che = 1
  
  # 꽉이 5개 모두 연결되지 않거나, 한 바퀴도 못 돈 경우  
  if i != 0 or che == 0:
    return False
  return True
  
for i in range(len(s)):
  if visited[i] == 'false':
    if check(i):
      answer += 1
    else:
      answer = -1
      break

print(answer)

