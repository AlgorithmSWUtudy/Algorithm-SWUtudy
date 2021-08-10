def solution(dartResult):
    answer = 0
    arr = []
    arr_score = []
    i = 0
    j = 0
    while i <len(dartResult):
        score = dartResult[i]
        if score == '1' and dartResult[i+1] == '0':
            score = int(10)
            i = i+1
        else:
            score = int(score)
        bonus = dartResult[i+1]
        if i+2 < len(dartResult) and not(dartResult[i+2].isdigit()):
            option = dartResult[i+2]
            i = i+3
        else:
            option = ""
            i = i+2

        if bonus == 'D':
            score = score ** 2
        elif bonus == 'T':
            score = score **3
            
        if option == "":
            arr_score.append(score)
        elif option =='*':
            if j == 0:
                arr_score.append(score * 2)
            else:
                arr_score[j-1] = arr_score[j-1] * 2
                arr_score.append(score * 2)
        elif option == '#':
            arr_score.append(-(score))
        j += 1
        
    return sum(arr_score)
