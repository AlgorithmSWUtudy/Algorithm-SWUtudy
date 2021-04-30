#https://dev-note-97.tistory.com/156
def solution(play_time, adv_time, logs):
    play_time = str_to_int(play_time)        # 1
    adv_time = str_to_int(adv_time)               
    all_time = [0 for i in range(play_time + 1)]

    for l in logs:                           # 2
        start, end = l.split('-')
        start = str_to_int(start)
        end = str_to_int(end)
        all_time[start] += 1
        all_time[end] -= 1

    for i in range(1, len(all_time)):       # 3
        all_time[i] = all_time[i] + all_time[i - 1]

    for i in range(1, len(all_time)):       # 4
        all_time[i] = all_time[i] + all_time[i - 1]

    most_view = 0                           # 5
    max_time = 0                          
    for i in range(adv_time - 1, play_time):
        if i >= adv_time:
            if most_view < all_time[i] - all_time[i - adv_time]:
                most_view = all_time[i] - all_time[i - adv_time]
                max_time = i - adv_time + 1
        else:
            if most_view < all_time[i]:
                most_view = all_time[i]
                max_time = i - adv_time + 1

    return int_to_str(max_time)

# 시간을 초로 바꿈
def str_to_int(time):
    h, m, s = time.split(':')
    return int(h) * 3600 + int(m) * 60 + int(s)


def int_to_str(time):
    h = time // 3600
    h = '0' + str(h) if h < 10 else str(h)
    time = time % 3600
    m = time // 60
    m = '0' + str(m) if m < 10 else str(m)
    time = time % 60
    s = '0' + str(time) if time < 10 else str(time)
    return h + ':' + m + ':' + s

# def solution(play_time, adv_time, logs):
#     answer = ''
#     h,m,s = map(int, playtime.split(':'))
#     temp = h*3600 + m*60 + s
#     array = [[0]*temp]
    
#     h,m,s = map(int, adv_time.split(':'))
#     adv_time_num = h*3600 + m*60 + s
    
#     for log in logs:
#         a,b = log.split()
#         array_temp = []
#         for _ in range(2):
#             h,m,s = map(int, playtime.split(':'))
#             temp = h*3600 + m*60 + s
#             array_temp = temp
#         for j in range(array_temp[0],array_temp[1]):
#             array[j]  = array[j]+1
        
#     max_num = max(array)
#     index = index(max_num)
#     for i in range(index,-1):
#         if array[i] != tmep:
#             fini_index = i
#             break
#     time = fini_index - index
#     if adv_time_num - time ==0:
#         answer = index/3600 + ':'+(index-(index/3600)*3600)/60 + ':'
#     else:
#     return answer
