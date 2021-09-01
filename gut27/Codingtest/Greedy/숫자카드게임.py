n,m = map(int, input().split())
data = []
answer = 0
for i in range(n):
  data.append(list(map(int, input().split())))
  #받아온 값 중 가장 작은 값중 가장 큰 값을 answer에 담기
  answer = max(answer, sorted(data[i])[0])
print(answer)
