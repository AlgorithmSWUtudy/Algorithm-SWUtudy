n = int(input())
arr = []
answer = 0
dict = {}
a_arr,b_arr,c_arr,d_arr = [], [], [], []
for _ in range(n):
  a,b,c,d = map(int,input().split())
  # 순서대로 들어간다는 조건이 있는것도 아니고 개수만 정해져 있기 때문에 이렇게 해도 된다.
  a_arr.append(a), b_arr.append(b), c_arr.append(c), d_arr.append(d)
#중복 없이 조합 구하기
for a in a_arr:
  for b in b_arr:
    if a+b in dict:
      dict[a+b] += 1
    else:
      dict[a+b] = 1 

for c in c_arr:
  for d in d_arr:
    # 반대 되는 결과가 사전에 있다면 횟수(조합의 수) 만큼 정답에 더하기
    if -(c+d) in dict:
      answer += dict[-(c+d)]

print(answer)
