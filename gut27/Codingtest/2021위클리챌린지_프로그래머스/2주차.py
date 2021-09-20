# 학점 반환
def check_score(avg):
    if avg>= 90:
        return 'A'
    elif avg >= 80:
        return 'B'
    elif avg >= 70:
        return 'C'
    elif avg >= 50:
        return 'D'
    return 'F'

def solution(scores):
    answer = ''
    for j in range(len(scores)):
        score = []
        type = 0
        # j학생에 대한 평가배열
        for i in range(len(scores)):
            score.append(scores[i][j])
        max_num = max(score)
        min_num = min(score)
        # 자기 자신에게 매긴 점수가 최고점이거나 최저점일때 같은 점수가 없다면 type = 1
        if (max_num == score[j]):
            type = score.count(max_num)
        elif (min_num == score[j]):
            type = score.count(min_num)
        if type == 1:
            avg = (sum(score)-score[j]) / (len(score)-1)
        else:
            avg = sum(score)/len(score)
        answer += check_score(avg)
    return answer
