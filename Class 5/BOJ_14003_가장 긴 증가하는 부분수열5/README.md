# LIS (NlgN), DP

LIS를 `O(NlgN)` 으로 풀이하는 알고리즘에 dp를 더한 문제이다<br>

- 이분탐색으로 구현한 알고리즘 내부에서 dp에 lis 값을 저장시킨다
- 동시에 lis의 최대값과 해당 값의 인덱스를 변수에 저장한다
- lis의 최대값 부터 역순으로 조건을 만족시키는 값을 쌓는다 (stack)

```C++
res.push_back(num[idx]);
    for(int i = idx - 1; i >=0; i--){
        if(dp[i] == dp[idx] - 1 && num[i] < num[idx]){
            res.push_back(num[i]);
            idx = i;
        }
    }
```
여기서 핵심은 dp[i]가 0~i 까지의 lis이기 때문에 dp끝(최대값)부터 역순으로 탐색해야되는 것이다