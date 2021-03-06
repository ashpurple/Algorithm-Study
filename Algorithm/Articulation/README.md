# Articulation Point & Bridge (단절점, 단절선)
![image](https://user-images.githubusercontent.com/75887645/156915398-61875a9b-a1da-43e8-aeae-477daa182dbb.png)

<정의 및 활용>
- 단절: 무방향 그래프에서 정점 또는 간선을 제거했을 때 그래프가 두개 이상으로 나누어지는 것
- 원리: 해당 정점 또는 간선을 지나지 않고 다른 정점으로 갈 수 있는 우회로가 없는경우 = 단절
- 핵심은 우회로 존재 유무 파악이며 이는 dfs와 discovered[i] 를 이용해 파악 할 수 있다
- 단절점일 경우는 다음과 같다
1. 정점이 루트 노드일때: 자식 노드가 2이상이면 단절점
=> 여기서 자식노드란 단순 연결 노드의 개수가 아닌 discover 되지않은 정점의 수를 뜻한다
2. 정점이 루트 노드가 아닐 때: 정점의 자식 노드가 정점을 지나지 않고 이전에 방문한 노드에 도달할 수 없으면 단절점
- 시간복잡도 `O(V+ E)`

<단절점 알고리즘>
1. 양방향으로 입력을 받는다
2. `dfs(int cur, int isRoot)`를 이용하여 i번째 노드부터 N번째 노드까지 탐색한다
=> `dfs(i, true)`를 N번 수행하는 이유는 그래프가 여러개일 경우에 대비해서이다<br>
만약 그래프가 하나로 이루어져있다면 해당 for문에선 dfs는 한번만 실행된다
3. dfs에서는 cur값을 1씩 증가시키며 discovered를 갱신해간다
4. discovered 되지 않은 child에 대해서 dfs를 재귀적으로 시행한다
5. dfs는 탐색한 정점 중 가장 빠른 탐색번호(discovered의 최소값)를 리턴한다
6. `int nextMin = dfs(nextMin, false)`로 얻은 탐색값과 현재의 탐색번호를 비교한다
=> prev가 현재 탐색번호 이상이면 단절점이다<br>
(다음 정점이 현재 정점을 지나지않고 이미 탐색된 정점으로 갈 수 없음을 의미)
7. 만약 루트 노드이면서 child가 2이상이면 단절점이다

<단절선 알고리즘><br>
기본 원리는 단절점 알고리즘을 따른다
- dfs 파라미터로 child 대신 이전의 노드(부모) 번호를 전달한다
=> self edge 판별에 활용
- 조건 만족시(`if(nextMin > discovered[cur])`) edge벡터에 단절선 저장
=> 문제에 따라 정렬, 우선순위 큐등 활용가능


본 알고리즘의 walkthrough는 해당 블로그를 참조하였다<br>
[Articulation Point And Bridge](https://bowbowbow.tistory.com/3)
