def solution(n, t, m, p):
    NOTATION = '0123456789ABCDEF'
    answer = ''
    temp_str = ''
    end = 0
    arr = []
    
    end = t*m
    for i in range(0,t*m):
        arr.append(i)
    
    for i in arr:
        temp = ''
        if i == 0:
            temp = '0'
        while i>0:
            i,r = divmod(i,n)
            temp += NOTATION[r]
        temp_str += temp[::-1]
        if len(temp_str) >= end:
            break
        
    for i in range(p-1, t*m, m):
        answer += temp_str[i]
    return answer
