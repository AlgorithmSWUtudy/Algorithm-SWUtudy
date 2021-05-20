def solution(citations):
    answer = 0
    b = 0
    citations.sort(reverse=True)
    print(citations)
    for n in range(len(citations)):
        if citations[n] >= n:
            b+=1
    
    answer = b

    return answer
