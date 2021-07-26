# Greedy

회의실의 끝시간을 기준으로 오름차 순으로 정렬한 뒤 <br>
첫원소부터 Greedy 적으로 탐색을 진행하였다.<br>

- Greedy 조건: 현재 회의의 끝시간 < 다음회의의 시작시간
- 조건 만족 시: count 후 다음회의의 끝시간을 저장

자료구조는 pair를 사용하였고 sort 함수에서 compare 조건을 pair.second의 오름차 순으로 주었다.