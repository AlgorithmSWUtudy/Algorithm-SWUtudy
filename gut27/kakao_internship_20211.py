def solution(numbers, hand):
    answer = ''
    
    arr = [1,2,3,4,5,6,7,8,9,'*',0,'#']
    arr_left= [1,4,7]
    arr_right = [3,6,9]
    arr_middle = [2,5,8,0]
    left = [3,0]
    right = [3,2]
    
    for num in numbers:
        if num in arr_left:
            answer += 'L'
            n= arr.index(int(num))
            left = [ n//3 ,n%3]
        if num in arr_right:
            answer += 'R'
            n= arr.index(int(num))
            right = [ n//3 ,n%3]
        if num in arr_middle:
            n= arr.index(int(num))
            indx = [ n//3 ,n%3]
            a2 = right[0]-indx[0]
            b2 = right[1] - indx[1]
            c2 = abs(a2) + abs(b2)
            a = left[0] - indx[0]
            b = left[1] - indx[1]
            c = abs(a) + abs(b)
            if c2 > c:
                answer += 'L'
                left = [ n//3 ,n%3]
            elif c2 < c:
                answer += 'R'
                right = [ n//3 ,n%3]
            else:
                if hand == 'right':
                    answer += 'R'
                    right = [ n//3 ,n%3]
                else:
                    answer += 'L'
                    left = [ n//3 ,n%3]

    return answer
