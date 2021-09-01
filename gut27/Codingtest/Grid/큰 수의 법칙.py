#입력 받기
n,m,k = map(int,input().split())
data = list(map(int,input().split()))
# 정렬, 제일 큰 수, 그 다음으로 큰 수를 알기 위해
data.sort(reverse=True)
answer = 0
i = 0
#m번 만큼 반복하기
while m > 0:
  answer += data[0]
  i+=1
m-=1
#k번 더할 시 2번째 큰 수 더하기
  if i == k and m!=0:
    answer += data[1]
    i = 0
    m-=1
print(answer)
