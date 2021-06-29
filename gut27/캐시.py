def solution(cacheSize, cities):
    answer = 0
    cache = []
    
    # 캐시가 0인경우 모근 값이 cache miss일테니 길이 * 5
    if cacheSize == 0:
        return len(cities) * 5
    
    for city in cities:
        # 대소문 구분 없기 때문에 전부 lower
        city = city.lower()
        # 캐시 안에 저장된 값의 경우 빼와서 순서를 제일 최근으로 바꿔줌, 캐시 힛
        if city in cache:
            indx = cache.index(city)
            cache.pop(indx)
            cache.append(city)
            answer += 1
        else:
        # 캐시 안에 저장 된 값이 아닌 경우 캐시미스, 제일 오래된 값을 제거 하고 최근 값으로 추가
            # 캐시가 꽉 차있을경우 제일 오래된 값을 없애고 추가
            if len(cache) == cacheSize:
                cache.pop(0)
                cache.append(city)
            else:
                cache.append(city)
            answer += 5
            
    return answer

# deque를 이용해 구현하는 방법 생각하기
# 사이즈가 0인경우를 고려 하지 못함 앞으로는 범위도 주의 깊게 생각하자 - 특히, 0 일때 어떻게 처리해야 할지
