from collections import deque
# 먼저 들어온 작업이 먼저 나가는 선입 선출 큐 문제
def solution(progresses, speeds):
    answer = []
    progresses = deque(progresses)
    speeds = deque(speeds)
    
    # 모든 작업이 끝날때까지 반복
    while progresses:
        # 개발
        for i in range(len(progresses)):
            if progresses[i] >= 100:
                continue
            progresses[i] += speeds[i]
        
        # 배포
        count = 0
        while progresses:
            if progresses[0] >= 100:
                count+=1
                speeds.popleft()
                progresses.popleft()
            else:
                break
        
        if count > 0:
            answer.append(count)
    return answer
