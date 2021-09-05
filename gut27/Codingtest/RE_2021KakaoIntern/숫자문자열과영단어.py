def solution(s):
    answer = ''
    n = 0
    # 영단어표를 딕셔너리로 만들기
    dict = {'ze':('0',4),'on':('1',3),'tw':('2',3),'th':('3',5),'fo':('4',4),'fi':('5',4),'si':('6',3),'se':('7',5),'ei':('8',5),'ni':('9',4)}
    while (n < len(s)):
      #숫자일 경우
        if s[n].isdigit():
            answer += s[n]
            n+=1
        else:
         # 숫자가 아닐경우 앞에 두글자를 키값으로 숫자와 단어 길이를 받아온다.
            #dict에 값 찾는법
            num, length = dict[s[n:n+2]]
            answer += num
            # 단어 길이만큼 인덱스 이동
            n += length
    return int(answer)
