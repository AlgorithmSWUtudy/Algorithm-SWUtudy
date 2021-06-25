def solution(lines):
    answer = 0
    dict = {}
    start_second = 1e9
    end_second = 0
    for line in lines:
        date, time, second = map(str,line.split(' '))
        temp = time.split(':')
        temp_time = int(temp[0])*3600+int(temp[1])*60+float(temp[2])
        second = second.replace('s','')
        temp[-1] = str(float(temp[-1])-float(second))
        temp_time2 = int(temp[0])*3600+int(temp[1])*60+float(temp[2])
        
        start_second = min(start_second,int(temp_time2))
        end_second = max(end_second,int(temp_time))

        if temp_time in dict:
            dict[temp_time] = dict[temp_time] + 1
        else:
            dict[temp_time] = 1
            
        if temp_time2 in dict:
            dict[temp_time2] = dict[temp_time2] + 1
        else:
            dict[temp_time2] = 1
            
        for i in dict:
            if temp_time2< i < temp_time:
                dict[i] = dict[i]+1

    for i in range(start_second, end_second):
        start = float(i) + 0.000
        end = float(i) + 0.999
        temp = 0
        for i in dict:
            if start<= i <= end:
                temp += dict[i]
                
        answer = max(answer,temp)
    
    return answer
