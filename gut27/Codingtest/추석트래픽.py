def solution(lines):
    answer = 0
    arr = []
    start = 1e9
    end = 0

    for i in range(len(lines)):
        temp_S = lines[i].split(' ')[1].split(':')
        temp_T = lines[i].split(' ')[2].replace('s','')
        Finish = int(int(temp_S[0])*3600+int(temp_S[1])*60 + float(temp_S[2])*1000)
        Start = int(Finish - (float(temp_T)*1000)+1)
        arr.append((Start,i))
        arr.append((Finish,i))
        start = min(start, Start)
        end = max(end,Finish)
    arr.sort()
    for i in range(start, end):
        Tp = []
        for ar in arr:
            if i <= ar[0] <=i+999 and ar[1] not in Tp:
                Tp.append(ar[1])
        answer = max(answer,len(Tp))
    if answer == 0:
        return 1
    return answer
