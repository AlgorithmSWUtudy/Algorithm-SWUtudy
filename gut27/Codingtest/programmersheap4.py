import heapq

def solution(operations):
    answer = []
    heap = []
    for ope in operations:
        o,n = ope.split(' ')
        if o == 'I':
            heapq.heappush(heap,int(n))
        else:
            if int(n) < 0 and len(heap) >= 1:
                heapq.heappop(heap)
            elif int(n) >= 0 and len(heap) >= 1:
                a = []
                for _ in range(len(heap)-1):
                    a.append(heapq.heappop(heap))
                heapq.heappop(heap)
                heap = a
    if len(heap) == 0:
        answer = [0,0]
        return answer
    else: 
        heap.sort(reverse = True)
        answer.append(heap[0])
        answer.append(heap[-1])
    return answer
