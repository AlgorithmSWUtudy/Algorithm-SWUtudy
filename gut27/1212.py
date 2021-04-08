num = input()
result = []
for i in range(len(num)):
  n = int(num[i])
  text_result = []
  for _ in range(3):
    text_result.append(str(n%2))
    n = int(n // 2)
  result.append("".join(text_result)[::-1])
temp = "".join(result)
while True:
  if temp[0] == '1':
    break
  temp = temp[1:]
print(temp)
