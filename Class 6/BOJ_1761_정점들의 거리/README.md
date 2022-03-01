# LCA

LCA의 기본 구현에 weight이 추가된 문제이다<br>
기존 LCA 구현에 dist[height][vertex] 배열만 추가해주면 된다<br>
주의할 점은 dp 업데이트 전에 sum값을 업데이트 해야된다

dp 및 dist 점화식
``` C++
dp[i][j] = dp[i - 1][dp[i - 1][j]];
dist[i][j] = dist[i - 1][j] + dist[i - 1][dp[i - 1][j]];
```