import re
def solution(new_id):
    answer = ''
    if re.search('[A-Z]',new_id):
        new_id = new_id.lower()
    if re.search('[^a-z0-9-_.]',new_id):
        new_id = re.sub('[^a-z0-9-_.]', '', new_id)
    if re.search('[.]{2,}',new_id):
        new_id = re.sub('[.]{2,}', '.', new_id)
    if new_id[0] == '.':
        new_id = new_id[1:]
    if len(new_id) != 0:
        if new_id[-1] == '.':
            new_id = new_id[0:-1]
    if len(new_id) == 0:
        new_id = "a"
    if len(new_id) >= 15:
        new_id = new_id[0:15]
        if new_id[-1] == '.':
            new_id = new_id[0:-1]
    if len(new_id) <= 2:
        temp = new_id[-1]
        for i in range(3):
            new_id += temp
            if len(new_id) == 3:
                break
    answer = new_id
    return answer
