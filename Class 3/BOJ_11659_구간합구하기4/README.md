# DP

dp에 누적합을 저장하였다<br>
점화식: dp[i] = dp[i - 1] + arr[i]<br>
구간합은 dp[b] - dp[a - 1] 로 구할 수 있다