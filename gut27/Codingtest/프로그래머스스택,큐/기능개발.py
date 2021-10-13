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

/*
다른 사람 코드
def solution(progresses, speeds):
    Q=[]
    # zip을 이용해 작업률과 속도를 합침
    for p, s in zip(progresses, speeds):
        # Q라는 배열에 작업일수와 배포가능한 작업의 개수를 더함
        if len(Q)==0 or Q[-1][0]<-((p-100)//s):
            Q.append([-((p-100)//s),1])
        else:
            Q[-1][1]+=1
    # 배포가능한 작업의 개수만 return
    return [q[1] for q in Q]

*/
