def binary(num,n):
    q = 0
    temp = ''
    for _ in range(n):
        q,r = divmod(num,2)
        temp += str(r)
        num = q
    return temp[::-1]


def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        a = binary(arr1[i],n)
        b = binary(arr2[i],n)
        temp_str = ''
        for j in range(len(a)):
            if a[j] == '0'and b[j] == '0':
                temp_str+= ' '
            else: 
                temp_str += '#'
        answer.append(temp_str)
    return answer
