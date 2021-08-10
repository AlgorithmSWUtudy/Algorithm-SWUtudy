#다시 풀기

from collections import deque

n = int(input())
arr = []
for _ in range(n+n-1):
	arr.append(list(map(int,input().split())))
dict={}
for i in range(n-1):
	for j in range(len(arr[i])):
		if arr[i][j] not in dict:
			dict[(i,arr[i][j])] = [(i+1,arr[i+1][j]),(i+1,arr[i+1][j+1])]
		else:
			dict[(i,arr[i][j])].append(((i+1,arr[i+1][j]),(i+1,arr[i+1][j+1])))
for i in range(n,n+n-1):
	for j in range(len(arr[i])):
		if j == 0:
			dict[(i,arr[i][j])] = [(i+1,arr[i+1][j])]
		if j == n-1:
			dict[(i,arr[i][j])].append((i+1,arr[i+1][j-1]))
		dict[(i,arr[i][j])].append(((i+1,arr[i+1][j-1]),(i+1,arr[i+1][j])))
sum_num = 0
count= n+n-1
result = 0
def find(start,dict,sum_num):
	sum_num += start[1]
	count -= 1
	#종료
	if count == 0:
		result = max(result,sum_num)
	x,y = dict[start]
	find(x,dict,sum_num)
	find(y,dict,sum_num)
find((0,arr[0]),dict,sum_num,count)
