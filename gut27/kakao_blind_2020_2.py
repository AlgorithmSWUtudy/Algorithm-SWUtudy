from itertools import combinations
from collections import Counter


def solution(orders, course):
    answer = []
    array_combi = []
    
    for c in course:
        array_combi = []
        for order in orders:
            order = sorted(order)
            combi = list(combinations(order,c))
            array_combi+=combi
        count = Counter(array_combi)
        if not count:
          return answer
        temp = max(count.values())
        for cou in count:
            if temp == count[cou] and count[cou] >= 2:
                answer.append("".join(cou))
    return answer
