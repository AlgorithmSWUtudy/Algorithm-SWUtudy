from itertools import combinations
from collections import Counter
def solution(sales, links):
    answer = 0
    result = 1e9
    for link in links:
        if link[0] in tree:
            tree[link[0]].append(link[1])
        else: 
            tree[link[0]] = link[1]
    
    key = tree.keys()
    value = tree.values()
    array_check = []
    
    for k in key:
        if k in value:
            array_check.append(k)
    
    combi = list(combinations(tree.items(),len(tree)-1))
    for com in combi:
        sum = 0
        for c in com:
            sum += sales[c-1]
        result = min(result, sum)
    return answer
