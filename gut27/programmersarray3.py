def solution(citations):
    answer = 0
    citations.sort(reverse=True)

    for n in range(len(citations)):
        if citations[n] >= n+1 and citations[n] != 0:
            answer+=1
        else:
            return answer
        
    return answer
