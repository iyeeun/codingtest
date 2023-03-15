# 브루트 포스

## 그냥 다 해보기

### 필요할 때
: 모든 경우의 수를 다 해보는 것, 방법의 개수에 따라 시간 제한에 걸릴 수도 있음

### 관련 알고리즘
1. 시간 복잡도 계산
2. 테스트케이스 수를 대입
3. 1초 = 1억 (100000000) 으로 보고 가능 여부를 판단

### 예제문제
- [백준](https://www.acmicpc.net/problem/2309) [2309번](./2309.cpp)

- [백준](https://www.acmicpc.net/problem/3085) [3085번](./3085.cpp)

    : 기준 세우기

- [백준](https://www.acmicpc.net/problem/1476) [1476번](./1476.cpp)

    : % 이용, 수의 범위를 보고 다 대입

- [백준](https://www.acmicpc.net/problem/1107) [1107번](./1107.cpp)

    : 범위가 괜찮다면 전체를 훑어보며 가능한지 파악하는 것도 좋은 방법임

- [백준](https://www.acmicpc.net/problem/14500) [14500번](./14500.cpp)

    : 좌표 배열로 나타내는 방법

## 건너 뛰며 해보기

### 필요할 때
: 특정 조건의 경우를 제외시킬 수 있을 때

### 예제문제
- [백준](https://www.acmicpc.net/problem/6064) [6064번](./6064.cpp)

    : 하나의 조건을 만족시킨 후 나머지 조건에 대해서만 탐색

- [백준](https://www.acmicpc.net/problem/1748) [1748번](./1748.cpp)

## N중 for문

### 필요할 때
: N개 중에 일부를 선택해야 하는 경우 BUT 쓰는 경우가 거의 없음

## N과 M

### 필요할 때
: 순서의 문제 or 선택의 문제

### 예제문제
- [백준](https://www.acmicpc.net/problem/15649) [15649번](./15649.cpp)

    : 골랐는지, 고른 배열은 무엇인지 등의 전역적 정보를 이용하여 recursive하게 할 수 있음

- [백준](https://www.acmicpc.net/problem/15650) [15650번](./15650.cpp)

    : 제외 조건

- [백준](https://www.acmicpc.net/problem/15651) [15651번](./15651.cpp)

- [백준](https://www.acmicpc.net/problem/15652) [15652번](./15652.cpp)

    : [선택의 문제](./15652_2.cpp)로도 볼 수 있음 (정렬 조건 -> 특정 제약이 들어가면서 가능)

- [백준](https://www.acmicpc.net/problem/15654) [15654번](./15654.cpp)

    : 응용

- [백준](https://www.acmicpc.net/problem/15655) [15655번](./15655.cpp)

- [백준](https://www.acmicpc.net/problem/15656) [15656번](./15656.cpp)

- [백준](https://www.acmicpc.net/problem/15657) [15657번](./15657.cpp)

- [백준](https://www.acmicpc.net/problem/18290) [18290번](./18290.cpp)

    : 2차원 -> 1차원으로 생각 가능 BUT 전부 같다고 생각하면 안됨 !! 기본적으로 2차원으로 다루어야 함

## 재귀

### 필요할 때
: n번째와 n+1번째 해결 방식에 특정한 패턴이 있는 경우

### 관련 알고리즘
: 특정한 기준이 필요함 -> 다음 경우 호출 / 정답을 찾은 경우 / 불가능한 경우로 나누기

### 예제문제
- [백준](https://www.acmicpc.net/problem/9095) [9095번](./9095.cpp)

    : 1, 2, 3으로 더한다는 동일한 패턴이 있음 + 원하는 숫자가 되었는지 아닌지 판단할 수 있음

- [백준](https://www.acmicpc.net/problem/1759) [1759번](./1759.cpp)

    : 순서대로 알파벳을 더한다는 패턴

- [백준](https://www.acmicpc.net/problem/14501) [14501번](./14501.cpp)