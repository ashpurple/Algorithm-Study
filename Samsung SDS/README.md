# 2022 SAMSUNG SDS WINTER ALGORITHM STUDY

## Day1, Day2 알고리즘 기초

### 알고리즘
- 알고리즘은 완전탐색으로 시작해 조건과 시간 복잡도에 따라 개선
- 조건: 정밀성, 유일성, 입출력, 유한성, 일반성
- 필요역량: 구현력(반복연습), 이론(학습), 응용력(문제풀이)
### DFS
- stack overflow 유의
- 백트래킹, 단절선 찾기, 위상정렬, 사이클 찾기 등에서 활용
### BFS
- 최단경로 찾기, 위상정렬 등에서 활용
- 최단 경로는 parent를 이용해 추적
### 완전탐색
- 알고리즘은 완전탐색에서부터 시작
- 시간복잡도가 크다면 개선하여 작게 만드는 것이 목표
### 재귀함수
- 하나의 문제를 여러 부분문제로 나누어 해결 (divide & conquer)
### 정렬
- 유일성 검사 / 중복제거 : 인접한 데이터와의 비교
- 빈도구하기: 정렬된 데이터를 한번씩만 확인하면 빈도 수 확인 가능
- 합집합 / 교집합: 2 pointers 알고리즘 이용
### Cycle Detect
- visited flag 하나만으로는 사이클 판별 불가
- unvisited, explored, visited 3개의 상태로 판별
- unvisited 면서 explored된 노드 만날 시 cycle (Back Edge)
### 이분탐색
- off-by-one error 주의
- lower bound(이상) / upper bound(초과)

## Day3 자료구조
