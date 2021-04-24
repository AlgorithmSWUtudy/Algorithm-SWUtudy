def solution(new_id):
    answer = ''
    check = 0
    temp = []
    arrays = ['-','_','.']
    id = new_id
    if new_id.islower()==False:
        check +=1
        id = id.lower()
    for i in range(len(id)):
        if any(array in id[i] for array in arrays) != True:
            if (id[i].islower() != True) and (id[i].isdigit() != True):
                temp.append(id[i])
    for i in range(len(temp)):
        id = id.replace(temp[i],"")
        check +=1
    for i in range(len(id)-1):
        if id[i:i+2]=='..':
            id = id.replace('..','.')
            check +=1
            i -= 1
    try:
        if id[0] == '.':
            id = id[1:]
            check +=1
        if id[-1] == '.':
            id = id[:-1]
            check +=1
    except:
        pass
    if len(id) == 0:
        id = 'a'
        check +=1
    if len(id)>=16:
        id = id[:15]
        if id[-1] == '.':
            id = id[:-1]
        check +=1
    while len(id) <=2:
        id = id + id[-1]
        check +=1
        
        
    if check == 0:
        return new_id
    else:
        return id
