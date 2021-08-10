def solution(info, query):
    answer = []
    new_info = []
    new_query = []
    for i in info:
        new_info.append(i.split(" "))
    for q in query:
      q = q.replace('and', '')
      q = q.replace('  ', ' ')
      new_query.append(q.split(' '))
    print(new_query)
    print(new_info)
    for querys in new_query:
      print(querys)
      result = 0
      for infos in new_info:
        if querys[0] != "-" and querys[0] != infos[0]:
          continue
        if querys[1] != "-" and querys[1] != infos[1]:
          continue
        if querys[2] != "-" and querys[2] != infos[2]:
          continue
        if querys[3] != "-" and querys[3] != infos[3]:
          continue
        if int(querys[4]) <= int(infos[4]):
          print(querys[4],infos[4])
          result+=1
      answer.append(result)
      print(result)
    return answer
