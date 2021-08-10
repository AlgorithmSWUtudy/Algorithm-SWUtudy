n = int(input())
result = 0
cow = [9]*11

for i in range(n):
  num, move = map(int, input().split())
  if cow[num] == 9 :
    cow[num] = move
  else:
    if cow[num] != move:
      result += 1
      cow[num] = move
print(result)
