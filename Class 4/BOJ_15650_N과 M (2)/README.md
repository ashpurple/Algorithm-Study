# Backtracking

재귀적 dfs를 이용해 순열을 구현했고 이 때 parameter로 i + 1값을 넘겨주어 <br>
for문을 i = i + 1부터 시작하게 하였다. (오름차순)<br>
이 때 순열의 탐색 값들은 `bool visted`으로 true에서 false로 swap 해주었다. (중복제거)