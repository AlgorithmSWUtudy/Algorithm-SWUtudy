from itertools import combinations

def solution(clothes):
    answer = 1
    dict= {}
    for name,kinds in clothes:
        if kinds in dict:
            dict[kinds].append(name)
        else:
            dict[kinds] = [name]
    arr=[]
    # dict.keys()
    for kinds in dict:
        answer *= len(dict[kinds]) + 1
    return answer -1
#     for i in range(1,len(dict.keys())+1):
#         arr += list(combinations(dict,i))
    
#     for ar in arr:
#         sum = 1
#         for a in ar:
#             sum = sum * len(dict[a])
#         answer+=sum
#     return answer
