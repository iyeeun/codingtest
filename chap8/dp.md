# 다이나믹 프로그래밍

## 다이나믹 프로그래밍

### 필요할 때
: 두 가지 속성을 만족하는 문제
1. Overlapping Subproblem
    : N번째 문제를 풀기 위해 N-k번째 문제의 답이 필요함
2. Optimal Substructure
    : N번째 문제를 풀기 위해 N-k번째 문제의 답이 그대로 사용됨
    -> N번째 문제의 답은 언제나 같음

### 관련 알고리즘
- 구현 방식
    1. Top-down
        : 주로 재귀함수 호출로 구현, 큰 문제를 작은 문제로 나눠가며 풀이
    2. Bottom-up
        : 주로 반복문으로 구현, 작은 문제에서부터 큰 문제를 구하면서 풀이
        - Memoization : 한 번 구한 문제의 정답을 저장해놓고 꺼내씀
- 문제 풀이 전략 (점화식 만들기)
    1. 점화식 정의
        : N번째 문제란 무엇인지 정의. 문제를 그대로 대입하는 방식을 처음에 사용 but 항상 같지 않을 수도 있음
    2. 작은 문제로 나누기
        : 큰 문제를 작은 문제로 어떻게 나타낼 수 있을지 말로 표현
    3. 점화식 만들기
        : 코드로 표현

### 예제문제
- [백준](https://www.acmicpc.net/problem/1463) [1463번](./1463.cpp)

    : '작은 문제'의 정의와 '가장 작은 문제'에 대해 잘 고민할 것 !!

- [백준](https://www.acmicpc.net/problem/11726) [11726번](./11726.cpp)

- [백준](https://www.acmicpc.net/problem/11727) [11727번](./11727.cpp)

    : 작은 문제로 나눌 때 가장 마지막 단계에 무엇이 올 수 있는지 생각해봐야 함

- [백준](https://www.acmicpc.net/problem/9095) [9095번](./9095.cpp)

- [백준](https://www.acmicpc.net/problem/11052) [11052번](./11052.cpp)

    : 방법의 수가 정해져있지 않은 경우에는 변수로 일반화하여 전부 확인

- [백준](https://www.acmicpc.net/problem/16194) [16194번](./16194.cpp)

- [백준](https://www.acmicpc.net/problem/) [번](./.cpp)

