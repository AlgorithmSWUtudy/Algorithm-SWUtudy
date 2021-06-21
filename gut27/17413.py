S = 'baekjoon online judge'
s = 0
temp = []
for i in range(len(S)):
  if '<' == S[i]:
    temp.append(i)
  if S[i] == '>':
    temp.append(i)

arr = []
if len(temp) == 0:
  arr.append(S)
elif temp[0] > 0:
  arr.append(S[0:temp[0]])
else:
  for i in range(len(temp)-1):
    if i % 2 == 0:
      arr.append(S[temp[i]:(temp[i+1]+1)])
    else:
      arr.append(S[(temp[i]+1):temp[i+1]])
if len(temp) > 0 and temp[-1] != (len(S)-1):
  arr.append(S[(temp[-1]+1):])

for a in range(len(arr)):
  if '<' in arr[a]:
    continue
  temp = arr[a].split(' ')
  for i in range(len(temp)):
    temp[i] = temp[i][::-1]
  arr[a] = ' '.join(temp)

print(''.join(arr))
