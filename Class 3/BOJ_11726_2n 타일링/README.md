# DP

n을 1부터 차례로 계산하면 1, 2, 3, 5, 8, 13 ... 과 같은 결과 값이 나온다 <br>

여기서 `dp[i] = dp[i - 1] + dp[i - 2]`  라는 점화식을 도출했고<br>
점화식을 이용해 목표 n 값까지 차례로 계산하여 구해주었다.
