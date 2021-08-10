n = int(input())
data = []
for i in range(n):
  data.append(input().split())

def ch_array(name1, name2):
  name1 = name1.lower()
  for i in range(10):
    if ord(name1[i]) >= ord(name2[i]):
      return 0 

data.sort(key = lambda x : x[1],reverse=True)
for i in range(n):
  print(data[i][0])

for i in range(n-1):
  if data[i][1] == data[i+1][1]:
    if data[i][2] <= data[i+1][2]:
      temp = data[i+1][2]
      data [i+1][2] = data[i][2]
      data[i][2] = temp
    elif data[i][2] == data[i+1][2]:
      if data[i][3] >= data[i+1][3]:
        temp = data[i+1][3]
        data [i+1][3] = data[i][3]
        data[i][3] = temp
      elif data[i][3] == data[i+1][3]:
          tp = ch_array(data[i][0], data[i+1][0])  
          if tp == 0:
            temp = data[i+1][0]
            data [i+1][0] = data[i][0]
            data[i][0] = temp

for i in range(n):
  print(data[i][0])
##################



n = int(input())
students = []

for _ in range(n):
  students.append(input().split())

students.sort(key = lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for student in students:
  print(student[0])
