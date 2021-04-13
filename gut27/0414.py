import re

def solution(inp_str):
  result = 0

  def first(inp_str):
    if 8<=len(inp_str)<=15:
      return True
    return False

  def second(inp_str):
    if len(re.sub('[\w~!@#$%^&*]', '', inp_str)) == 0:
      return True
    return False

  def third(inp_str):
    count = 0
    if re.search('[a-z]',inp_str):
      count+=1
    if re.search('[A-Z]',inp_str):
      count+=1
    if re.search('[0-9]',inp_str):
      count += 1
    if re.search('[~!@#$%^&*]',inp_str):
      count += 1
    if count >= 3:
      return True
    return False

  def fourth(inp_str):
    count = 0
    for i in range(len(inp_str)-1):
      if inp_str[i] == inp_str[i+1]:
        count+=1
      else:
        if count >= 3:
          return False
        count = 0
    if count >= 3:
      return False
    return True

  def fifth(inp_str):
    if re.search('[a-z]{5,}|[A-Z]{5,}|[0-9]{5,}|[~!@#$%^&*]{5,}',inp_str):
      return False
    return True

  if first(inp_str) != True:
    result +=1
  if second(inp_str) != True:
    result+=1
  if third(inp_str) != True:
    result += 1
  if fourth(inp_str) != True:
    result +=1
  if fifth(inp_str) != True:
    result+=1
  
  return result

inp_str = "aabbaao23"

print(solution(inp_str))
