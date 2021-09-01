N, K = map(int, input().split())
result = 0
while (N!=1):
  # 과정 2번
  if N%K == 0:
    N = N//K
    result += 1
  # 과정 2가 안 될시
  else:
    result += N%K 
    if result == 0:
      result -=1
      break
    N = N//K
    result += 1
print(result)
