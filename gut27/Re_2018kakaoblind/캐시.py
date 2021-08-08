from collections import deque

def solution(cacheSize, cities):
    queue = deque(maxlen = cacheSize)
    answer = 0
    for city in cities:
        city = city.lower()
        if city in queue:
            answer += 1
            queue.remove(city)
            queue.append(city)
        else:
            queue.append(city)
            answer += 5
    return answer

//append-  오른쪽 삽입, popleft 왼쪽에서 빼기
