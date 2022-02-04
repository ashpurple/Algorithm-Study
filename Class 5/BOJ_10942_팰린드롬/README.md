# DP

2차원 dp를 활용하였다<br>

팰린드롬의 특성을 이용해 dp를 정의하였다

`bool dp[a][b]`: a~b 까지 팰린드롬 여부 

<점화식><br>
1. 초기화<br>
   `dp[i][i] = true`
   ```C++
      if(num[i] == num[i + 1])
            dp[i][i + 1] = true;
   ```

2. 팰린드롬의 특성 활용
```C++
 if(num[i] == num[j] && dp[i + 1][j - 1])
                dp[i][j] = true;
```

답: a부터 b까지 팰린드롬 여부 = dp[a][b]<br>