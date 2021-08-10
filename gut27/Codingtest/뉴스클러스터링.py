import re
def solution(str1, str2):
    answer = 1
    temp = ''
    arr_str1 = []
    arr_str2 = []
    
    for i in range(len(str1)-1):
        if str1[i].isalpha() and str1[i+1].isalpha():
            arr_str1.append(str1[i:i+2])
            
    for i in range(len(str2)-1):
        if str2[i].isalpha() and str2[i+1].isalpha():
            arr_str2.append(str2[i:i+2])
    
    if len(arr_str2) == 0 and len(arr_str1) == 0:
        return 65536

    arr_intersection = []
    visited = [False] * len(arr_str2)   
    
    for i in range(len(arr_str1)):
        for j in range(len(arr_str2)):
            if arr_str1[i].lower() == arr_str2[j].lower() and visited[j] == False:
                arr_intersection.append(arr_str2[j])
                visited[j] = True
                break

    union = len(arr_str1) + len(arr_str2) -len(arr_intersection)
    answer = int((len(arr_intersection) / union) *65536)
            
    return answer
