def Range(n,r):
    if r == 'D':
        n = n * n
    elif r == 'T':
        n = n * n * n
    return n
    
def Option(n,o):
    if o == '*':
        if len(arr) == 0:
            n = n * 2
        else:
            n =n *2
            arr[-1] = arr[-1]*2
    else:
        n = -n
    return n
    
def solution(dartResult):
    global arr
    arr = []
    i = 0
    while (i < len(dartResult)):
        n = dartResult[i]
        if n == '1' and dartResult[i+1] == '0':
            n = '10'
            r = dartResult[i+2]
            i += 3
        else:
            r = dartResult[i+1]
            i += 2
        if i < len(dartResult) and (dartResult[i] == '*' or dartResult[i] == '#'):
            o = dartResult[i]
            arr.append(Option(Range(int(n),r),o)) 
            i += 1
        else:
            arr.append(Range(int(n),r))
            
    return sum(arr)
