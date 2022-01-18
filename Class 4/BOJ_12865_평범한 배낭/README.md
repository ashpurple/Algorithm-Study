# DP (Knapsack Problem)

2차원 dp를 활용하였다<br>

dp[i][j]: j 크기의 가방에서 i번째 데이터까지의 Value 최대값<br>
ex) dp[3][6] = 5: 3번째 데이터까지 사이즈 6이 가질 수 있는 최대값은 5<br><br>
<점화식><br>
1. 물건의 크기가 j 초과 일때 (물건을 넣지 못할 때)
   `dp[i][j] = dp[i - 1][j];` 이전값 유지

2. 물건의 크기가 j 이하 일 때
`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);`<br>
=> max(넣지 않을 때 value, 넣을 때 value + 잉여 공간의 최대 값)
답: dp의 마지막 행 마지막 열<br>
