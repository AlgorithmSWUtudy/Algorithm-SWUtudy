def solution(arr):
    answer = 1
    num = [2,3,5,7,11,13,17,19,23,27,29,31,37,41,43,47]
    dict = {}
    for a in arr:
        flag = 0
        for i in range(len(num)):
            count = 0
            while (a % num[i])==0:
                a = a // num[i]
                count += 1
            if count == 0:
                continue
            else:
                if num[i] in dict:
                    if count > dict[num[i]]:
                        dict[num[i]] = count
                else:
                    dict[num[i]] = count
            flag= 1
            if a == 0:
                break
        if flag == 0:
            if a in dict:
                dict[a] = dict[a]+1
            else:
                dict[a] = 1
        
    for k in dict.keys():
        answer = answer * (k ** dict[k])
    
    return answer
