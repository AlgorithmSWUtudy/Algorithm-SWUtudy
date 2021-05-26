def solution(brown, yellow):
    answer = []
    num_sum = brown + yellow
    arr = []
    for y in range(3, (num_sum//3)+1):
        if num_sum % y ==0:
            x = num_sum//y
            if (x-2)*(y-2) == yellow:
                answer = [x,y]
                return answer
