# 전형적인 bfs 문제

#실패원인1. 모든 방향에서의 이동이 아님
#실패 2. 함수 종료지점이 잘못됨

from collections import deque
def solution(board):
    answer = 0
    n = len(board)
    arr_copy = [[0]*n for _ in range(n)]
    
    dx = [0,0,1,1,1]
    dy = [1,-1,0,1,-1]
    def bfs(x1,y1,x2,y2):
        queue = deque()
        queue.append((x1,y1,x2,y2))
        while queue:
            x1,y1,x2,y2 = queue.popleft()
            for i in range(5):
                nx1 = x1 + dx[i]
                ny1 = y1 + dy[i]
                nx2 = x2 + dx[i]
                ny2 = y2 + dy[i]

                if i == 3:
                    nx1 = x2
                    ny1 = y2
                    nx2 = x1 + dx[i]
                    ny2 = y1 + dy[i]
                if i == 4:
                    nx1 = x1
                    ny1 = y1
                    nx2 = x2 + dx[i]
                    ny2 = y2 + dy[i]
                if nx1 < 0 or nx1>= n or ny1<0 or ny1>=n or nx2 < 0 or nx2>= n or ny2<0 or ny2 >= n:
                    continue
                if board[nx1][ny1] == 1 or board[nx2][ny2] == 1:
                    continue
                if i == 3 and board[x1+1][y1] == 1:
                    continue
                if i == 4 and board[x2+1][y2] == 1:
                    continue
                queue.append((nx1,ny1,nx2,ny2))
                arr_copy[nx2][ny2] = arr_copy[x1][y1] + 1
        print(arr_copy)
        return arr_copy[n-1][n-1]
    answer = bfs(0,0,0,1)
    return answer
board = [[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]
print(solution(board))
