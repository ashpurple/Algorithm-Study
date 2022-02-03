# DFS (Cycle detect)

dfs를 활용하여 cycle을 찾아주었다<br>

finished 변수를 추가로 사용하여 재방문을 판단하였다

다만 문제는 cycle을 이루지 않는 노드들의 개수를 구하므로<br>
visited 변수를 bool 값이 아닌 int로 두어 탐색 번호를 지정하였으며<br>
cycle이 발생할 때 cycle의 시작점과 끝점의 탐색 번호를 빼주는 계산으로 개수를 구하였다