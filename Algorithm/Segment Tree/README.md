# Segment Tree

세그먼트 트리의 리프 노드와 리프 노드가 아닌 다른 노드는 다음과 같은 의미를 가집니다.

- 리프 노드: 배열의 그 수 자체
- 다른 노드: 왼쪽 자식과 오른쪽 자식의 합을 저장함

![image](https://user-images.githubusercontent.com/75887645/148227804-cee19294-ce2b-42b6-9c66-b95c3a08d9b8.png)

### 장점
- 수정이 빈번하게 일어나는 구간합 문제에서 효율적
- 탐색 및 수정 `O(logN)`, M번 탐색 또는 수정 `O(MlogN)`
- Range Update 가능

### 특징
- Top Down 방식으로 구현
- 데이터 삽입 시 Post-Order 방식 적용
- Leaf노드의 Index번호를 따로 구해야 함

### 만들기
만약, N이 2의 제곱꼴인 경우에는 Full Binary Tree 입니다. 또, 그 때 높이는 `lgN`입니다. 리프 노드가 N개인 Full Binary Tree는 필요한 노드의 개수가 `2*N-1개` 입니다.

N이 2의 제곱꼴이 아닌 경우에는 높이가 `H = ceil(lgN)`이고, 총 세그먼트 트리를 만드는데 필요한 배열의 크기는 `2^(H+1) - 1`개가 됩니다.

### 합찾기
### ex) 5-8 구간의 합
![image](https://user-images.githubusercontent.com/75887645/148233860-583d53ac-e799-421b-9c2f-f7a29cc6018c.png)

### 업데이트
### ex) 5 변경
![image](https://user-images.githubusercontent.com/75887645/148234060-82eaeefb-84a7-4dd0-8504-fb658ff6bce9.png)
