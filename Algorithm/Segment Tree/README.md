# Backtracking

백트래킹은 DFS에 <b>가지치기 (Pruning)</b> 를 통해 유망하지 않은 노드는 고려하지 않고 탐색하는 완전탐색 기법이다.<br>
DFS에서 답이 될 가능성이 없는 노드로 빠져 무한히 깊은곳을 탐색하게 되면 굉장히 비효율적이다.<br>
그래서 이러한 비효율적인 경로를 차단하고 목표지점에 도달 가능한 루트를 검사하는 방법이 백트래킹 알고리즘이다.

![image](https://user-images.githubusercontent.com/75887645/129026191-41e1d250-f67f-460f-81d5-9849350e0530.png)

### 용어
- CSP(Constrain Satisfaction Problmes): 조건을 만족하는 문제
- Promising: 유망한 노드, CSP에 해당하는 노드
- Pruning(가지치기): CSP에 해당되지 않은 노드
- Backtracking: 다시 상위 노드로 회귀, pruning일 때 수행

### 알고리즘
1. root 노드 부터 dfs 실행
2. 유망한 노드인지 점검(CSP 만족)
3. 유망하면 해당 노드의 하위 노드 탐색
4. 유망하지 않으면 백트래킹 수행(Pruning)

활용 문제: dfs를 활용한 조건 만족 문제 ex) N-queens, 순열, 조합 
