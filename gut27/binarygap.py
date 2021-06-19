def solution(N):
    arr = []
    answer = 0
    while N!=0:
        arr.append(N%2)
        N = N // 2
    arr.reverse()
    if arr.count(1) <= 1:
        return answer
    else:
        count = 0
        for i in arr:
            if i == 1:
                answer = max(answer,count)
                count = 0
            else:
                count += 1
    return answer
