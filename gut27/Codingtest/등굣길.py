#1.동적 탐색은 동적 탐색으로 풀자
#2. 문제 꼼꼼히 읽기, puddles 행렬 바꿔서 넣는거 몰라서 푸는데 한참 걸림
from collections import deque
def solution(m, n, puddles):
    answer = 0
    arr=[[0]*m for _ in range(n)]
    for x,y in puddles:
        arr[y-1][x-1] = -1
    arr[0][0] = 1
    
    def dp(x,y):
        if x < 0 or y<0 or arr[x][y] <0:
            return 0
        if arr[x][y] >0:
            return arr[x][y]
        
        arr[x][y] = dp(x,y-1)+dp(x-1,y)
        
        return arr[x][y]
    answer = dp(n-1,m-1)%1000000007
    return answer
