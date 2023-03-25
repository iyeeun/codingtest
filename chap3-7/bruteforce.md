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

## 백트래킹

### 필요할 때
: 브루트 포스에서 더이상 **함수 호출이 의미가 없는 경우를 제외**하고 진행

### 예제문제
- [백준](https://www.acmicpc.net/problem/14889) [14889번](./14889.cpp)

    : 서로 크기가 달라지는 상황을 제외시킴

- [백준](https://www.acmicpc.net/problem/15661) [15661번](./15661.cpp)

- [백준](https://www.acmicpc.net/problem/2529) [2529번](./2529.cpp)

- [백준](https://www.acmicpc.net/problem/1248) [1248번](./1248.cpp)

    : 종료 조건, 호출 조건 정의 + 제외 상황 구현

## 순열

### 필요할 때
: 순서가 중요한 브루트 포스 문제의 경우 활용 가능

### 관련 알고리즘
: 순열 구하는 알고리즘
1. 첫 순열 구하기 : 전체에 대해 비내림차순
2. 다음 순열 구하기
    - c++ : ```<algorithm>```의 ```next_permutation(start, end)``` 함수
    - 로직
        - A[i-1] < A[i]를 만족하는 가장 큰 i 찾기
        - j >= i 면서 A[j] > A[i-1]를 만족하는 가장 큰 j 찾기
        - A[i-1]과 A[j] swap
        - A[i]부터 순열 뒤집기
3. 마지막 순열 구하면 종료 : 전체에 대해 비오름차순

### 예제문제
- [백준](https://www.acmicpc.net/problem/10972) [10972번](./10972.cpp)

- [백준](https://www.acmicpc.net/problem/10973) [10973번](./10973.cpp)

- [백준](https://www.acmicpc.net/problem/10974) [10974번](./10974.cpp)

- [백준](https://www.acmicpc.net/problem/10819) [10819번](./10819.cpp)
 
    : 전부 ```next_permutation``` / ```prev_permutation``` 함수 이용하면 금방 풀리는 문제

- [백준](https://www.acmicpc.net/problem/10971) [10971번](./10971.cpp)

    : N개의 중복 제거를 위해서는 첫 번째 자리 고정 => ```next_permutation(arr.begin()+1, arr.end())```

- [백준](https://www.acmicpc.net/problem/6603) [6603번](./6603.cpp)

    : 선택의 문제를 0과 1의 순열로 표현할 수 있음 => M개의 1과 N-M개의 0의 순열

## 비트마스크

### 필요할 때
: 선택의 문제의 경우 0 또는 1로 표현되는 비트마스크를 이용할 수 있음. 공간을 적게 사용하고 빠르다는 장점이 있지만 나타낼 수 있는 범위가 한정적임.

### 관련 알고리즘
- 숫자 S에 특정한 수 n이 포함되어 있는지 검사 : ```S & (1 << n)```
- 숫자 S에 특정한 수 n을 추가 : ```S | (1 << n)```
- 숫자 S에 특정한 수 n을 제거 : ```S & ~(1 << n)```
- 숫자 S에 특정한 수 n을 토글 : ```S ^ (1 << n)```
- 모든 부분 집합에 대하여 포함된 경우에 처리
    ```:cpp
    for(int i = 0; i < (1 << n); i ++) {
        for(int j = 0; j < n; j ++) {
            if(i & (1 << j)) {
                // 처리
            }
        }
    }
    ```

### 예제문제
- [백준](https://www.acmicpc.net/problem/11723) [11723번](./11723.cpp)

    : 기본적인 비트 연산 연습 문제

- [백준](https://www.acmicpc.net/problem/1182) [1182번](./1182.cpp)

    : 공집합 제외 -> for(int i = 1; ~)

- [백준](https://www.acmicpc.net/problem/14889) [14889번](./14889_2.cpp)

- [백준](https://www.acmicpc.net/problem/14391) [14391번](./14391.cpp)