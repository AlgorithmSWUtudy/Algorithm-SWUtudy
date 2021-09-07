S = input()
answer = int(S[0])
for i in range(1,len(S)):
  num = int(S[i])
  if num == 0:
    continue
  elif num ==1:
    answer += 1
  else:
    if answer == 0:
      answer += num
    else:
      answer *= num
print(answer)
