arr = []
for _ in range(4):
  arr.append(input())
n = int(input())
arr_turn = []
for _ in range(n):
  arr_turn.append(list(map(int,input().split())))

answer = 0

def turn(arr_check,arr):
  for i in range(4):
    if arr_check[i][0] == False:
      continue
    if arr_check[i][1] == 1:
      temp = arr[i][-1]
      temp += arr[i][0:-1]
      arr[i] = temp 
    else: 
      temp = arr[i][1:]
      temp += arr[i][0]
      arr[i] = temp

def check(num,rot,arr):
  arr_check = [[False,0] for _ in range(4)]
  arr_check[num] = [True,rot]

  for i in range(num, 3):
    if (num % 2 == 0 and i % 2 == 0) or (num % 2 == 1 and i % 2 == 1):
        temp = -rot
    else:
        temp = rot
    if arr[i][2] != arr[i+1][6]:
      arr_check[i+1] = [True,temp]
    else:
      break
  
  for i in range(num,0, -1):
    if (num % 2 == 0 and i % 2 == 0) or (num % 2 == 1 and i % 2 == 1):
        temp = -rot
    else:
        temp = rot
    if arr[i][6] != arr[i-1][2]:
      arr_check[i-1] = [True,temp]
    else:
      break
  turn(arr_check,arr)

for num, rot in arr_turn:
  check(num-1,rot,arr)

if arr[0][0] == '1':
  answer += 1
if arr[1][0] == '1':
  answer += 2
if arr[2][0] == '1':
  answer += 4
if arr[3][0] == '1':
  answer += 8

print(answer)
