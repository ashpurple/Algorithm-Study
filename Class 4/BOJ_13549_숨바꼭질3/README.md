# BFS, DP

bfs는 모든 가지가 가중치가 일정하다고 가정한 알고리즘이다<br>
따라서 bfs에 dp를 적용시켜 시간의 최소값만 배열에 저장하였다<br>
즉 더 깊은 노드가 얕은 노드보다 비용이 작을 수 있다<br>

dp[loc]: 해당 위치까지의 시간 최소값<br>

```
if(0 <= loc - 1 && dp[loc - 1] > dp[loc] + 1){
            q.push(loc - 1); // X - 1
            dp[loc - 1] = dp[loc] + 1;
        }
        if(loc + 1 < MAX && dp[loc + 1] > dp[loc] + 1){
            q.push(loc + 1); // X + 1
            dp[loc + 1] = dp[loc] + 1;
        }
        if((loc << 1) < MAX && dp[loc << 1] > dp[loc]){
            q.push(loc << 1); // X^2
            dp[loc << 1] = dp[loc];
        }
```