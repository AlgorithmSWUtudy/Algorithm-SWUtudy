from itertools import combinations

n,m = map(int,input().split())
result = 0
temp = 0
cards = list(map(int,input().split()))
find_cards = list(combinations(cards,3))
for i in range(len(find_cards)):
  temp = sum(find_cards[i])
  if temp <= m:
    result = max(temp, result)
print(result)
