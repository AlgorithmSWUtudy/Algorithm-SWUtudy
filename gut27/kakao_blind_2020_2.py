from itertools import combinations
def solution(orders, course):
    answer = []
    array_combi = []
    array_temp = []
    array_course = {}
    
    for order in orders:
        for i in range(len(order)+1):
            order = sorted(order)
            for combi in combinations(order, i):
                if len(combi) in course:
                    array_combi.append("".join(combi))
    for combi in array_combi:  
        if len(combi) not in array_course and array_combi.count(combi) >= 2 and len(combi) in course:
            array_course[len(combi)] = [(combi, array_combi.count(combi))]
        elif len(combi) in array_course and array_combi.count(combi) >= 2 and len(combi) in course and combi not in array_course[len(combi)]:
            array_course[len(combi)].append((combi, array_combi.count(combi)))

    for i in course:
        try:
            if len(array_course[i]) == 2:
                answer.append(array_course[i][0])
            else: 
                array_temp = list(array_course[i])
                array_temp.sort(key=lambda x: -x[1])
                temp = array_temp[0][1]
                answer.append(array_temp[0][0])
                for j in range(1, len(array_temp)):
                    if temp == array_temp[j][1] and array_temp[j][0] not in answer:
                        answer.append(array_temp[j][0])
        except:
            continue
    answer.sort()
    return answer
