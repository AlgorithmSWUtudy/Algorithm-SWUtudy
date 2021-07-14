s = list(input())
answer = 0
visited = ['false']*len(s)
def check(num):
  duck = ['q','u','a','c','k']
  che = 0
  i = 0
  for n in range(num,len(s)):
    if visited[n] == 'false' and s[n] == duck[i]: 
      visited[n] = 'true'
      i = (i+1)%5
      if i == 0:
        che = 1
  if i != 0 or che == 0:
    return False
  return True
for i in range(len(s)):
  if visited[i] == 'false':
    if check(i):
      answer += 1
if answer == 0:
  print(-1)
else:
  print(answer)


