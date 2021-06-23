def solution(msg):
    answer = []
    dictionary = ['','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    i = 0
    while i < len(msg):
        end = i+1
        for j in range(i+1,len(msg)):
            if msg[i:(j+1)] in dictionary:
                end = j +1
            else:
                break
        answer.append(dictionary.index(msg[i:end]))
        dictionary.append(msg[i:end+1])        
        i = end
    return answer
