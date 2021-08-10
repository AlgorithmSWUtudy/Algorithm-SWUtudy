array = [0]*21
array[0] = 0
array[1] = 1
n = int(input())

for i in range(2,n+1):
  if n <= 1:
    break
  array[i] = array[i-1]+array[i-2]

print(array[n])
