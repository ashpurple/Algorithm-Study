# Permutation (순열)

![image](https://user-images.githubusercontent.com/75887645/129135951-11501a32-17ba-4347-9de0-57e2271b99ee.png)

순열(nPm)이란 n개의 수 중 m의 길이를 갖는 순서쌍을 의미한다.<br>
이는 <b>backtracking</b>으로 구현할 수 있다.<br>
visited[i]을 활용해 true 처리를 하며 dfs()를 진행하다 해당 길이에 도달하면 dfs()가 종료되며 다시 false 처리를 해준다.<br>
이때 for문에서 visited[i]이 true 일 때만 위 코드를 실행한다.(pruning)

- 출력하고자하는 순열의 길이는 m 값을 조절하여 구현할 수 있다
- 오름차순 또는 중복 순열의 경우 parameter 값을 하나 늘려 for 문의 i 를 해당 값부터 실행해주면 된다.<br>
ex) `dfs(int start){ ... for(int i = start; ..) ... dfs(i + 1) ...}`

