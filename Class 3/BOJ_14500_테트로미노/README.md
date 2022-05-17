# BFS, 구현

DFS를 이용해 완전탐색으로 구현하였다

블록은 대칭과 회전이 모두 가능하므로 5개의 도형중 4개의 도형은 dfs로 탐색한 모든 경우의수로 커버할 수 있다 (완전탐색)<br>
하지만 ㅗ모양의 블럭은 dfs로 커버할 수 없으므로 따로 4가지 경우를 체크해주었다

DFS의 구현은 다음과 같다
```C++
visited[nx][ny] = true;
dfs(nx, ny, depth + 1, sum + map[nx][ny]);
visited[nx][ny] = false;
```