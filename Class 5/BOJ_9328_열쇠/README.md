# BFS

bfs를 활용한 구현 문제이다<br>

주요 구현 사항
- goEntrance(): 가장자리의 입구를 큐에 넣어주는 함수
- isPossible(): margin, visit, 벽 등 이동이 가능한지 판단
- 키를 발견시 visit을 초기화하고 goEntrance()함수를 이용해 재탐색
- 키와 문서를 발견시 map을 .으로 바꿔준다