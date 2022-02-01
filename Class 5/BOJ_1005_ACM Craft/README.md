# Topology Sort

위상정렬의 응용 문제이다

위상 정렬 코드에서 엣지 제거후 새로운 노드를 큐에 추가할 때 다음 코드를 삽입하면된다.

```C++
for(int v: building[u]){
                if(--inDegree[v] == 0) q.push(v);
                if(dist[v] < dist[u] + cost[v]) // dp
                    dist[v] = dist[u] + cost[v];
            }
```

즉 각 노드까지 걸리는 최단 시간을 갖는 dp배열을 만들어 줌으로써 해결할 수 있다