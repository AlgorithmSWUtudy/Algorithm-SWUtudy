S = 'noojkeab enilno egduj'
S = S.split('>')
for i in range(len(S)):
  if '>' in S[i]:
    S[i] = S[i].split('>')
print(S)
for ar in arr:
  temp = ''
  if '<' in ar:
    continue
  ar = ar.split(' ')
  for a in ar:
    temp += a.reverse
  ar = temp

print(''.join(arr))
