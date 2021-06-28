def solution(m, n, board):
    answer = 0
    for i in range(m):
        board[i] = list(board[i])
    while 1:
        arr = []
        visited = [[False]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == m-1 or j == n-1:
                    continue
                if board[i][j] == 0:
                    continue
                if board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1]:
                    if visited[i][j] == False:
                        arr.append((i,j))
                        visited[i][j] = True
                    if visited[i][j+1] == False:
                        arr.append((i,j+1))
                        visited[i][j+1] = True
                    if visited[i+1][j] == False:
                        arr.append((i+1,j))
                        visited[i+1][j] = True
                    if visited[i+1][j+1] == False:
                        arr.append((i+1,j+1))
                        visited[i+1][j+1] = True
        if len(arr) == 0:
            break
        else:
            answer += len(arr)
        
        for x,y in arr:
            board[x][y] = 0
        
        for j in range(n):
            for i in range(0, m):
                if board[i][j] == 0:
                    for x in range(i, 0, -1):
                        board[x][j] = board[x-1][j]
                        board[x-1][j] = 0
                    
    return answer
