n = int(input())
length = (n-1)*4 + 1
arr = [['']*length for _ in range(length)]
flag = 0
flag2 = 0
s = 0
e = length
for i in range(length):
  for j in range(s,e):
    if flag == 0:
      arr[i][j] = '*'
    else:
      arr[i][j] = ' '
  if s == (e-1):
    flag2 = 1
  if flag2 == 0:
    s += 1
    e -= 1
  else:
    s -= 1
    e += 1
  if flag == 0:
    flag = 1
  else:
    flag = 0

flag = 0
flag2 = 0
s = 0
e = length
for j in range(length):
  for i in range(s,e):
    if flag == 0:
      arr[i][j] = '*'
    else:
      arr[i][j] = ' '
  if s == (e-1):
    flag2 = 1
  if flag2 == 0:
    s += 1
    e -= 1
  else:
    s -= 1
    e += 1
  if flag == 0:
    flag = 1
  else:
    flag = 0

for i in range(length):
  print(''.join(arr[i]))
