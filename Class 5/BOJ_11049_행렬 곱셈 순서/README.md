# Divide and Conquer, DP

분할정복과 dp를 통해 해결하는 문제이다<br>

먼저 행렬의 곱은 부분 행렬의 곱으로 이루어져 있으므로 3개 이상의 행렬곱에 대해서는 재귀적으로 쪼개준다

또한 DP를 이용해 i 부터 j까지 행렬의 곱 중 최소값을 저장해준다

`int dp[i][j]`: i 부터 j까지 행렬의 곱 최소값

핵심 코드는 다음과 같다
```C++
   for(int i = start; i < end; i++){ // 3 or more matrix
      result = divide(start,i) + divide(i+1,end) + multiply(start, i ,end);
      if(dp[start][end] == 0 || result < dp[start][end]) 
         dp[start][end] = result;
   }
   return dp[start][end];
```