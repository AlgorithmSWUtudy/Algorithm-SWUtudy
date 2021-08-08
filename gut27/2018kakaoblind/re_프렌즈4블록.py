def solution(m, n, board):
    answer = 0
    while(True):
        remove = []
        for i in range(m):
            board[i] = list(board[i])
        for i in range(m-1):
            for j in range(n-1):
                if board[i][j] == '':
                    continue
                if board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1]:
                    if (i,j) not in remove:
                        remove.append((i,j))
                    if (i,j+1) not in remove:
                        remove.append((i,j+1))
                    if (i+1,j) not in remove:
                        remove.append((i+1,j))
                    if (i+1,j+1) not in remove:
                        remove.append((i+1,j+1))
        if len(remove) == 0:
            break
        else:
            answer+= len(remove)
            
        for i,j in remove:
            board[i][j] = ''
        for j in range(n):
            for i in range(m):
                if board[i][j] == '':
                    for x in range(i,0,-1):
                        board[x][j] = board[x-1][j]
                        board[x-1][j] = ''
    return answer
