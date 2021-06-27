def solution(files):
    answer = []
    temp_arr = []
    for i in range(len(files)):
        tail = 0
        num = 0
        for j in range(len(files[i])):
            if files[i][j].isdigit():
                num = j
                break
        for j in range(num+1,len(files[i])):
            if not files[i][j].isdigit():
                tail = j
                break

        if tail > 0: 
            temp = files[i]
            temp_arr.append((temp[0:num],temp[num:tail],temp[tail:],temp))
        else:
            temp = files[i]
            temp_arr.append((temp[0:num],temp[num:],'',temp))

    temp_arr.sort(key=lambda x:(x[0].lower(),int(x[1])))

    for t in temp_arr:
        answer.append(t[-1])
            
    return answer
