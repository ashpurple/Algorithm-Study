# 재귀함수(dfs)를 이용한 순열과 조합 구현
순열 또는 조합의 모든 경우의 수를 출력하고자 할 때 유용하다.<br>
단순 경우의 수만 구하는 문제에서는 시간복잡도가 높아 적합하지않다. (순열: `O(n!)`, 조합: `O(2^n)`)

## Permutation (순열)

![image](https://user-images.githubusercontent.com/75887645/129135951-11501a32-17ba-4347-9de0-57e2271b99ee.png)

순열(nPm)이란 n개의 수 중 m의 길이를 갖는 순서쌍을 의미하며 이는 백트래킹으로 구현 가능하다.<br>
`visited[i]`을 활용해 true 처리를 하며 `dfs()`를 진행하다 해당 길이에 도달하면 `dfs()`가 종료되며 다시 false 처리를 해준다.<br>
이때 for문에서 `visited[i]`가 true 일 때만 위 코드를 실행한다.(pruning)

- 출력하고자하는 순열의 길이는 m 값을 조절하여 구현할 수 있다
- 중복 순열의 경우 visited[i] 조건을 빼주면 된다(완전 탐색)<br>

## Combination (조합)

![image](https://user-images.githubusercontent.com/75887645/130314356-66777f02-278d-427b-a0c0-65afeb4311cd.png)

조합(nCm)이란 n개의 수 중 m의 길이를 갖고 순서를 갖지 않은 쌍을 의미한다.<br>
이는 `dfs(int start)`로 파라미터를 하나 더 추가함으로써 구현할 수 있다.<br>
for문에서 i는 start부터 시작하며 `dfs(i + 1)`를 재귀적으로 호출한다.

- 출력하고자하는 조합의 길이는 m 값을 조절하여 구현할 수 있다
- 중복 조합의 경우 `dfs(i + 1)`대신 `dfs(i)`를 호출하면 된다.


