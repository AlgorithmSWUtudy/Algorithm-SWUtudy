from collections import Counter

def solution(gems):
    answer = []
    count = Counter(gems)
    gem_num = len(count) 
    result = 1e9
    interval_sum = 0
    end = -1

    for start in range(len(gems)):
        while interval_sum < gem_num and end < len(gems):
            end += 1
            interval_sum = len(Counter(gems[start:end+1]))
            
        if interval_sum == gem_num:
              if abs(end-start) < result and interval_sum == len(Counter(gems[start:end+1])):
                result = end-start
                answer=[start+1,end+1]
        interval_sum = len(Counter(gems[start:end+1]))

    return answer

gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
print(solution(gems))
