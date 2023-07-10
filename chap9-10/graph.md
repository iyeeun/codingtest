# 큐와 그래프

## 큐

### 정의
: 한쪽 끝으로 자료를 넣고 다른 쪽에서만 뺄 수 있는 구조, First In First Out

### 필요할 때
: 두 가지 속성을 만족하는 문제
1. Overlapping Subproblem
    : N번째 문제를 풀기 위해 N-k번째 문제의 답이 필요함
2. Optimal Substructure
    : N번째 문제를 풀기 위해 N-k번째 문제의 답이 그대로 사용됨
    -> N번째 문제의 답은 언제나 같음

### 관련 알고리즘
- 구현
    : 일차원 배열 + front/back에 대한 index 정보

### 예제문제
- [백준](https://www.acmicpc.net/problem/13023) [13023번](./13023.cpp)

- [백준](https://www.acmicpc.net/problem/1260) [1260번](./1260.cpp)

- [백준](https://www.acmicpc.net/problem/11724) [11724번](./11724.cpp)

- [백준](https://www.acmicpc.net/problem/1707) [1707번](./1707.cpp)

- [백준](https://www.acmicpc.net/problem/2667) [2667번](./2667.cpp)

- [백준](https://www.acmicpc.net/problem/2178) [2178번](./2178.cpp)

- [백준](https://www.acmicpc.net/problem/2667) [2667번](./2667.cpp)