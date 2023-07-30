# 그래프와 BFS

## 그래프 알고리즘
- 사이클 찾기 : **이전 칸과 다른 칸으로 이동했을 때 이미 방문한 칸을 방문**했으면 사이클이 존재함
- 입력이 올바른 BFS/DFS 결과인지 파악 : 입력 순서에 따라 adjacent list를 sort하고 BFS/DFS를 수행한 결과와 같은지 확인

### 예제문제
- [16929번 Two Dots](https://www.acmicpc.net/problem/16929) ([51분](./16929.cpp))
    1. 사이클 확인 : 이전 칸과 다른 칸으로 이동했을 때 이미 방문한 칸을 방문했으면 사이클이 존재함
    2. 방문 처리 : 호출하기 전에 방문한 것으로 처리하면 안됨

- [16947번 서울 지하철 2호선](https://www.acmicpc.net/problem/16947) ([60분](./16947.cpp))
    : 역대급으로 어려웠던 문제,, 사이클을 찾기 위해 DFS를 이용하고 거리를 찾기 위해 BFS를 이용하는 문제
    1. 순환선(사이클) 확인 : 노드와 엣지의 개수가 동일 -> 딱 하나의 사이클을 가짐
        - 방법 : DFS
            1. 이전 노드로 가지 않았지만 이미 방문한 노드를 방문함
                ```
                1. 종료 조건 : 이미 방문한 노드를 방문함 -> 사이클 존재
                2. 노드 방문 처리
                3. 다음 호출 : 인접한 노드가 이전에 방문한 노드가 아니고 갈 수 있는 조건을 만족할 때, 다음을 호출
                ```
            2. 길이가 3 이상이고 이미 방문한 노드를 방문함
    2. 정점과 순환선 사이의 거리 찾기
        - 방법 : BFS
            ```
            기본적인 BFS를 이용하며 거리를 계산해줌
            1. 사이클에 속하는 노드들을 전부 큐에 넣음
            2. 각 노드의 인접한 노드들에 대해 거리가 아직 정해지지 않은 노드에만 1) 큐에 푸시 2) 길이 정함
            -> BFS이므로 처음으로 접근한 거리가 가장 최소임
            ```

- [12946번 육각 보드](https://www.acmicpc.net/problem/12946) ([55분](./12946.cpp))
    1. 육각 보드를 서로 다른 색으로 칠할 때의 색의 최대 개수 : 3
    2. 0 : 칠할 칸이 없을 때 / 1 : 칸이 서로 인접하지 않을 때 / 2 : 이분 그래프일 때 / 3 : 그 외
    3. -> 이분 그래프 판단 문제로 바뀌게 됨
        - DFS가 호출됨 -> 칸이 있음 -> 1
        - 서로 인접한 칸에 대해 2팀으로 나누어 색을 칠함 (color / -color) -> 이분그래프임 -> 2
        - 나와 같은 색이 이미 칠해진 인접 노드가 있으면 이분 그래프가 아님 -> 3

- [16940번 BFS 스페셜 저지](https://www.acmicpc.net/problem/16940) ([111분](./16940.cpp))
    1. 맨 처음에는 depth순으로 정렬하는 것으로 접근 : depth가 같은 노드 간 순서가 중요한 것이라서 틀린 답안이었음
    2. BFS를 수행하면서 순서 확인하는 방법
        ```
        1. n개의 인풋에 대해 BFS를 수행함. 이 때, 큐가 비었다면 잘못된 순서임.
        2. front가 지금 보는 인풋 노드랑 다른 경우에도 잘못된 순서임.
        3. 현재 인풋 노드의 인접 노드들 중 아직 방문하지 않은 경우에 대해 front로 parent를 설정해줌.
        4. 아까 설정해준 노드들에 대해 순서를 넘어가버리거나 인풋 노드의 parent가 front가 아닌 경우는 잘못된 순서임.
        ```
        : 이 때 인덱스 설정 등 많은 부분이 이해하기 어려웠음
    3. 입력 순서로 인접 리스트 정렬을 이용하는 방법 ([7분](./16940_2.cpp))
        ```
        1. 인접 리스트를 입력된 순서로 정렬함
        2. BFS를 진행할 때 입력 순서와 다른 경우 잘못된 순서임
        ```
        : 이 코드가 더 이해하기 쉬운듯

- [16964번 DFS 스페셜 저지](https://www.acmicpc.net/problem/16964) ([31분](./16964.cpp))
    1. BFS와 비슷하게 입력 순서로 정렬하고 DFS를 수행하여 비교함
    -> DFS 조건 때문에 잘 안됐었는데, 일단 수행하고 거르는(?) 방법을 사용하자

## BFS
- 목적 1. 모든 노드를 한 번씩 방문 2. 모든 가중치가 1일 때의 최단 거리 찾기

### 예제문제
- [16928번 뱀과 사다리 게임](https://www.acmicpc.net/problem/16928) ([39분](./16928.cpp))
    1. 중간 단계를 생략 해도 됨 -> 뱀과 사다리로 인한 이동은 따로 표시하지 않음