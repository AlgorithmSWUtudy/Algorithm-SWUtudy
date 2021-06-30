def solution(n, t, m, timetable):
    answer = ''
    for ti in range(len(timetable)):
        temp = timetable[ti].split(':')
        timetable[ti] = int(temp[0])*60 + int(temp[1])
    arr = []
    
    end = (n-1) *t
    for i in range(0,end+1,t):
        temp = 9*60 + i
        arr.append(temp)
    
    before, point = timetable[0],timetable[0]
    count = m
    timetable.sort()
    length = n
    first =  timetable[ti]
    for ar in range(len(arr)):
        count = m
        for ti in range(len(timetable)):
            if arr[ar] >= timetable[ti] and timetable[ti] != -1:
                if count ==0:
                    break
                count-=1
                if timetable[ti] == before:
                        continue
                else:
                    point = timetable[ti]
                    before = timetable[ti]
                timetable[ti] = -1
            
        length -= 1
        if length ==0:
            break
    if length == 0:
        if count == 0:
            if point == first:
                r,q = divmod(point-1, 60)
                return str(r).zfill(2)+':'+str(q).zfill(2)
            else:
                r,q = divmod(point, 60)
                return str(r).zfill(2)+':'+str(q).zfill(2)
        
    r,q = divmod(arr[-1], 60)
    return str(r).zfill(2)+':'+str(q).zfill(2)
                

# def solution(n, t, m, timetable):
#     answer = ''
#     for ti in range(len(timetable)):
#         temp = timetable[ti].split(':')
#         timetable[ti] = int(temp[0])*60 + int(temp[1])
#     arr = []
    
#     end = (n-1) *t
#     for i in range(0,end+1,t):
#         temp = 9*60 + i
#         arr.append(temp)
        
#     for i in range(0,len(arr)-1):
#         count = m
#         for j in range(len(timetable)):
#             if count == 0:
#                 break
#             if timetable[j] != -1 and arr[i]>timetable[j]:
#                 count -= 1
#                 timetable[j] = -1
#     table = []
#     for t in timetable:
#         if t != -1:
#             table.append(t)
    
#     count = 0
#     table.sort()
#     for t in table:
#         if arr[-1] >= t and t != -1:
#             count += 1
#     if count < m:
#         r,q = divmod(arr[-1], 60)
#         return str(r).zfill(2)+':'+str(q).zfill(2)
#     else:
#         point = table[0]
#         count = m
#         before = table[0]
#         for t in table:
#             if arr[-1] >= t:
#                 count -= 1
#                 if count >0:
#                     if t == before:
#                         continue
#                     else:
#                         point = t
#                         before = t
#                 else:
#                     break
#     if point == 0:
#         r,q = divmod(table[i]-1, 60)
#         return str(r).zfill(2)+':'+str(q).zfill(2)
#     else:
#         r,q = divmod(point, 60)
#         return str(r).zfill(2)+':'+str(q).zfill(2)
        
#     return answer
    
# solution(2,1,2,["09:00", "09:00", "09:00", "09:00"])

# def solution(n, t, m, timetable):
#     answer = ''
#     # 값을 int로 바꿔서 계산 편의 도모
#     for t in range(len(timetable)):
#         temp = timetable[t].split(':')
#         timetable[t] = int(temp[0])*60 + int(temp[1])
    
#     # 셔틀 버스 시간을 모두 담는다.
#     arr = []
#     for i in range(0,n,t):
#         temp = 9*60 + i
#         arr.append(temp)
    
#     # 맨 마지막 셔틀시간을 제외하고 각 셔틀 시간마다 탈 수 있는 사람들을 -1 로 바꿈
#     for i in range(0,len(arr)-1):
#         count = 0
#         for j in range(len(timetable)):
#             if count == 0:
#                 break
#             if timetable[j] != -1 and arr[i]>timetable[j]:
#                 count -= 1
#                 timetable[j] = -1
    
#     # 남은 사람들 저장
#     table = []
#     for t in timetable:
#         if t != -1:
#             table.append(t)
    
#     #남은 사람중 셔틀에 타는 사람수모두 구함
#     count = 0
#     for t in table:
#         if arr[-1] > t:
#             count += 1
    
#     # 셔틀 정원 보다 작을 시 셔틀 도착시간에 줄섬
#     if count < m:
#         r,q = divmod(arr[-1], 60)
#         return str(r).zfill(2)+':'+str(q).zfill(2)
#     else:
#     # 아닐시 포인트를 이용해서 가자 늦게 설수있는 순간을 구한다.
#         point = 0
#         count = m
#         before = 0
#         for t in table:
#             if arr[-1] > t:
#                 count -= 1
#                 if count >0:
#                     if t == before:
#                         comtinue
#                     else:
#                         point = before
#                 else:
#                     break
#     if point == 0:
#         r,q = divmod(table[i]-1, 60)
#         return str(r).zfill(2)+':'+str(q).zfill(2)
#     else:
#         r,q = divmod(point, 60)
#         return str(r).zfill(2)+':'+str(q).zfill(2)
        
#     return answer
    
# solution(1,1,5,["08:00", "08:01", "08:02", "08:03"])
