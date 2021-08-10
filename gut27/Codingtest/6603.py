from itertools import combinations
arr= []
arr_k= []
while 1:
  temp = list(map(int,input().split()))
  if temp[0] == 0:
    break
  arr_k.append(temp[0])
  arr.append(temp[1:])

for i in range(0, len(arr)):
  arr_c = []
  for c in combinations(arr[i],6):
    for j in c:
      print(j,end=" ")
    print()
  print()
