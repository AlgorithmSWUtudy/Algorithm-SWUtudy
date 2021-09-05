def solution(places):
    answer = []
    def check(x,y,n):
        place = places[n]
        for i in range(x,5):
            for j in range(5):
                if place[i][j] == 'P':
                    distance = abs(x-i)+abs(y-j)
                    if distance == 1:
                        return 0
                    elif distance <=2:
                        if (i == x or j == y):
                            if (i == x and j < y and place[i][j+1] != 'X') or (i == x and j > y and place[i][y+1] != 'X') or (i < x and j == y and place[i+1][y] != 'X') or (i > x and j == y and place[x+1][y] != 'X'):
                                return 0
                        elif (i != x and j != y):
                            if (i >x and (place[x+1][y] != 'X' or place[x][j] != 'X')) or (i < x and (place[x-1][y] != 'X' or place[x][j] != 'X')): return 0
                    
    for n in range(5):
        bk = 'false'
        for i in range(5):
            for j in range(5):
                if places[n][i][j] == 'P':
                    if check(i,j,n)==0:
                        answer.append(0)
                        bk = 'true'
                        break
            if bk == 'true':
                break
        if bk == 'false':
            answer.append(1)
                        
    return answer
