# Kruskal

![UnionFindKruskalDemo](https://user-images.githubusercontent.com/75887645/151643571-c3e928a1-aaec-4fae-9208-8657444cb94e.gif)

<정의>
- MST를 구하는 알고리즘
- MST: 모든 노드를 최소한의 비용으로 연결하는 부분트리
- 시간복잡도 `O(ElgE)` (간선 중심)
- 간선의 개수에 영향을 받으므로 간선이 매우 많을 때는 프림알고리즘이 적합
- Union-Find 알고리즘으로 사이클 판단

<구현>
- Edge 구조체와 벡터 선언 (Edge 중심의 알고리즘이므로 Edge로 구성된 1차원 벡터만 이용)
- root는 자기 자신으로 초기화 (Union-Find)
- `isCycle(int, int)`는 부모가 같으면 true를 반환

<원리>
1. Edge를 weight의 오름차순으로 정렬한다
2. Edge를 순서대로 방문하며 사이클이 아닌 경우 sum에 weight을 더해준다
3. 또한 Union을 이용해 해당 노드가 연결되어있음을 처리해준다
4. 모든 Edge를 탐색할 때까지 2,3 반복
