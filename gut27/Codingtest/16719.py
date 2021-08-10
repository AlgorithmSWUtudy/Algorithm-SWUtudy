from collections import deque

queue = deque()
n = input()
text = []
for i in range(len(n)):
  text.append((ord(n[i]),i))
result = []

def find_text(temp):
  result_text = []
  text_fist = sorted(temp, key=lambda x:x[0])[0]
  result.append(text_fist)
  result.sort(key=lambda x:x[1])
  for i in result:
    result_text.append(chr(i[0]))
  print("".join(result_text))
  index = temp.index((text_fist[0],text_fist[1]))
  if len(temp[index+1:]) != 0:
    find_text(temp[index+1:])
  if len(temp[:index]) != 0:
    find_text(temp[:index])
  

text_fist = sorted(text, key=lambda x:x[0])[0]
result.append(text_fist)
print(chr(text_fist[0]))
find_text(text[text_fist[1]+1:])
find_text(text[:text_fist[1]])
