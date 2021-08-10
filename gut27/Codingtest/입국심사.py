#뭘 이분 탐색 해야하는지 잘 생각해보자
def solution(n, times):
    answer = 0
    l = 1
    r = max(times) * n
    
    while l <r:
        mid = (l + r) //2
        sum = 0
        for t in times:
            sum += mid // t
        if sum >= n:
            r = mid
        else:
            l = mid + 1
    answer = l
    return answer
