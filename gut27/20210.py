n = int(input())
#arr = []
#for _ in range(n):
#  arr.append(input())

arr = ['Foo1Bar',
'Foo12Bar',
'Foo3bar',
'Fo6Bar',
'Foo00012Bar',
'Foo3Bar',
'foo4bar',
'FOOBAR']

att=['A','a','B','b']
print(sorted(att))
def compare(str1,str2):
  list1 = []
  list2 = []
  for i in range(len(str1)):
    if str1[i].isalpha():
      list1.append(str1[i])
    else:
      temp = ''
      temp+= str1[i]
      for j in range(i+1,len(str1)):
        if str1[j].isDigit():
          temp+= str1[j]
        else:
          break
      list1.append(int(temp))
  for i in range(len(str2)):
    if str2[i].isalpha():
      list2.append(str2[i])
    else:
      temp = ''
      temp+= str2[i]
      for j in range(i+1,len(str2)):
        if str2[j].isDigit():
          temp+= str2[j]
        else:
          break
      list2.append(int(temp))
  length = 0
  if len(list1) >= len(list2):
    length = len(list1)
  else:
    length = len(list2)

  for i in range(length):
    if list1[i].isalpha() and list2[i].isalpha():
      if (list1[i].isupper() and list2[i].isupper()) or (list1[i].isupper() and list2[i].isupper()):
        if list1[i] > list2[i]:
          return False
      if list1[i].upper() > list2[i].upper():
          return False 
    if list1[i].isalpha() and list2[i].isDigit():
      if list1[i] > list2[i]:
          return False
    if list1[i].isDigit() and list2[i].isalpha():
      if list1[i] < list2[i]:
          return False
    if list1[i].isDigit() and list2[i].isDigit():
      if list1[i] > list2[i]:
          return False
      if list1[i] == list2[i]:
        
while True:
  for i in range(n):
    compare(arr[i],arr[i+1])

