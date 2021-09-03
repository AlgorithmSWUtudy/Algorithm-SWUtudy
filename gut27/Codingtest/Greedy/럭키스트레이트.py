N = input()
mid = len(N)//2
if sum(N[:mid]) == sum(N[mid:]):
  print("LUCKY")
 else:
  print("READY")
