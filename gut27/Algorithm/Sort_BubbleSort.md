## Bubble Sort
#### [정의]
- 인접한 2개의 원소를 비교해 크기가 순서대로 되어 있지 않으면 서로 교환한다.

#### [로직]
[step 0] n 번째 원소와 n+1번째 원소를 비교하여(n은 1부터 시작) 조건에 맞지 않으면 서로 교환한다.
[step 1] 한 회차가 끝나면 맨 뒤의 원소(=졍렬된 원소)를 제외하고 step0을 반복한다.

#### [예제]
```Python
def bubble_sort(arr):
    end = len(arr) - 1
    while end > 0:
        last_swap = 0
        for i in range(end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                last_swap = i
        end = last_swap
```

#### [시간복잡도]
O(N^2)
버블 정렬은 정렬이 되어있건, 안되어있건 2개의 원소를 비교하기 때문에 최악의 경우, 최선의 경우, 평균의 경우 모두 시간 복잡도가 O(N^2)으로 동일하다.

#### [공간복잡도]
O(N)

#### [장점]
- 구현이 간단하고 소스코드가 직관적이다.
- 정렬하고자 하는 배열 안에서 정렬하는 방식이므로, 다른 메모리 공간을 필요로 하지 않는다.
- 안정 정렬이다.
#### [단점]
- 시간 복잡도가 최악, 최선, 평균 모두 O(N^2)이므로 비효율적이다.
- 순서에 맞지 않은 요소를 인접한 요소와 교환한다.
- 하나의 요소가 가장 왼쪽에서 가장 오른쪽으로 이동하기 위해서는 배열에서 모든 다른 요소들과 교환되어야 한다.
* 일반적으로 자료의 교환 작업(SWAP)이 자료의 이동 작업(MOVE)보다 더 복잡하기 때문에 버블 정렬은 단순성에도 불구하고 거의 쓰이지 않는다.

## [참고 서적 및 사이트]
사이트 : https://github.com/WooVictory/Ready-For-Tech-Interview/blob/master/Algorithm,
https://gmlwjd9405.github.io/2018/05/06/algorithm-bubble-sort.html
