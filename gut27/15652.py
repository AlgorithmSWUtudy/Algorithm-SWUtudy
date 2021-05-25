from itertools import product

n,k = map(int,input().split())
arr = []
for i in range(1,n+1):
  arr.append(str(i))
arr_p = list(product(arr,repeat=k))
for p in arr_p:
  flag = True
  for i in range(k-1):
    if p[i] > p[i+1]:
      flag = False
      break
  if flag:
    print(" ".join(p))
  
