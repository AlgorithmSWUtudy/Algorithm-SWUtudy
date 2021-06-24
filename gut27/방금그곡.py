#시험끝나고 다시 짜기
def solution(m, musicinfos):
    answer = ''
    arr = []
    num = 0
    for mus in musicinfos:
        s,e,t,i = mus.split(',')
        x,y = map(int,e.split(':'))
        x2,y2 = map(int,s.split(':'))
        time =  abs(y2-y) + (abs(x2-x)*60)
        temp = time % len(i)
        song = i * (time//len(i)) + i[0:temp]
        arr.append((t,song,time,len(i),num))
        num+=1
    length = len(m)
    arr.sort(key=lambda x:(-x[2],x[4]))

    for ar in arr:
        t,i,time,l_i,num = ar
        for j in range(0,time-length+1):
            if i[j:j+length] == m:
                if j+length-1 < l_i:
                    return t
                else:
                    try:
                        if i[j+length] != '#':
                            return t
                        else:
                            continue
                    except:
                        continue
    if len(answer) == 0:
        answer='(None)'
                    
    return answer
