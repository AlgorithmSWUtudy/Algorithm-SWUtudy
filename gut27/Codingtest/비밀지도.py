# 이진수 만드는 함수
def change(num,n):
    q = 0
    temp = ''
    for _ in range(n):
        q,r = divmod(num,2)
        temp += str(r)
        num = q
    return temp[::-1]


def solution(n, arr1, arr2):
    answer = []
    arr_sum = [[0]*n for _ in range(n)]

    # 복호화
    for i in range(n):
        arr1[i] = change(arr1[i],n)
        arr2[i] = change(arr2[i],n)

    for i in range(n):
        for j in range(n):
            # 모두 공백일 경우 '' 
            if arr1[i][j] == '0' and arr2[i][j] == '0':
                arr_sum[i][j] = ' '
            else:
                arr_sum[i][j] = '#'
        answer.append(''.join(arr_sum[i]))
        
    return answer

# bin으로 하려다가 실패함 0xb때문에 어떻게 해야하는지 찾아보기 문자로 바꾸는 방법
