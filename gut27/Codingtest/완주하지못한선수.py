from collections import Counter
def solution(participant, completion):
    answer = ''
    
    participant += completion
    count = Counter(participant)

    if count.most_common()[-1][1] == 1:
        answer = count.most_common()[-1][0]
    else:
        for k,v in count.items():
            if v % 2 != 0:
                answer = k 
    return answer
