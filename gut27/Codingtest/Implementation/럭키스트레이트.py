  
N = map(int, list(input()))
# 리스트 string to int
N = list(map(int,N))
mid = len(N)//2
if sum(N[:mid]) == sum(N[mid:]):
  print("LUCKY")
else:
  print("READY")
