# DP

점화식
```C++
dp[i] = min(dp[i], 1 + dp[i - j * j]);
```