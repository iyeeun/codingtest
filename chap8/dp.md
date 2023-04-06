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

#### 연속에 대한 처리 예제
    : 연속에 대한 조건 -> 마지막으로 온 것을 따로 저장하여 처리

- [백준](https://www.acmicpc.net/problem/15990) [15990번](./15990.cpp)

    : 자료형 주의..

- [백준](https://www.acmicpc.net/problem/10844) [10844번](./10844.cpp)

- [백준](https://www.acmicpc.net/problem/2193) [2193번](./2193.cpp)

#### 증가에 대한 처리 예제
    : 각 원소가 증가하고 있다면 마지막만 증가하면 됨

- [백준](https://www.acmicpc.net/problem/11053) [11053번](./11053.cpp)

    : 특정한 작은 문제의 답이 아니라, 어떤 조건을 만족하는 최대/최소를 이용하는 것도 가능!

- [백준](https://www.acmicpc.net/problem/14002) [14002번](./14002.cpp)

    : 리스트까지 출력해야 할 때 -> 값이 변경될 때의 이유를 기록한 뒤 역추적

<br><br>

- [백준](https://www.acmicpc.net/problem/1912) [1912번](./1912.cpp)

    : 가능한 방법을 열거한 후 작은 문제로 나누는 것도 좋은 방법

- [백준](https://www.acmicpc.net/problem/1699) [1699번](./1699.cpp)

    : 처음에는 마지막 단계를 단순히 1씩 감소하는 형태?로 생각했었는데 통과가 되긴 했지만 무척 [느렸음](./1699_2.cpp) -> 제곱수가 마지막에 온다는 것을 파악!

- [백준](https://www.acmicpc.net/problem/2225) [2225번](./2225.cpp)

    : 점화식 잘 세우기!

- [백준](https://www.acmicpc.net/problem/14501) [14501번](./14501.cpp)

    : 재귀 + 메모이제이션도 가능! 풀지는 않았고 코드만 첨부함.

- [백준](https://www.acmicpc.net/problem/15988) [15988번](./15988.cpp)

    : 먼저 구해놓고 출력해주기

- [백준](https://www.acmicpc.net/problem/1149) [1149번](./1149.cpp)

    : 그 전까지의 비용이 최소면 나도 최소 + 조건을 만족시키기 위한 종류 나누기 + 조건도 그 전과 나만 맞으면 전체가 조건 만족함 (연속)

- [백준](https://www.acmicpc.net/problem/1309) [1309번](./1309.cpp)

    : 연속 + 조건이 붙으면 그 조건을 세부적으로 나눠보고 해당 경우를 나눠서 저장 (2차원 배열 이용), 마지막 단계를 확인할 때 조건에 맞게 배치 가능한 수 확인

- [백준](https://www.acmicpc.net/problem/11057) [11057번](./11057.cpp)

    : 얘도 연속 + 조건. 경우로 나누고 subproblem 확인하기, 추가 변수 쓸 때는 다 나열해보고 규칙 & 범위 찾기

- [백준](https://www.acmicpc.net/problem/2156) [2156번](./2156.cpp)

    : 연속에 대한 조건이 i-1보다 더 넓은 범위일 경우, **연속의 횟수 자체를 변수로 이용함**

- [백준](https://www.acmicpc.net/problem/1932) [1932번](./1932.cpp)

    : index를 변수로 이용

- [백준](https://www.acmicpc.net/problem/11055) [11055번](./11055.cpp)

- [백준](https://www.acmicpc.net/problem/11722) [11722번](./11722.cpp)

    : 뒤에서부터 구하는 것도 가능함 (N->1)

- [백준](https://www.acmicpc.net/problem/11054) [11054번](./11054.cpp)

    : 앞 + 뒤에서 채우기

- [백준](https://www.acmicpc.net/problem/13398) [13398번](./13398.cpp)


