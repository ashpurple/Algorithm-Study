# DP

그리디적으로 접근하여 dp에 최대 값을 저장였다<br>
점화식: dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]<br>
마지막 dp 행의 최대값이 답이된다