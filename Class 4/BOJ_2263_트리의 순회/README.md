# Divide and Conquer

In-order와 Post-order를 입력받아 Pre-order를 출력하는 문제이다

먼저 트리를 직접 작성해보면서 In-order와 Post-order로 얻을 수 있는 정보를 찾는 것이 중요하다

Post-order는 루트노드가 항상 마지막 인덱스에 저장되어있다는 특징이있고 In-order는 루트 노드의 인덱스를 기준으로 왼쪽은 왼쪽 tree 오른쪽은 오른쪽 tree가 있다는 특징이있다

우리가 구하려는 Pre-order의 특징은 항상 루트노드를 출력한다는 것이므로 
세가지 특징을 이용한 알고리즘은 다음과 같다
1. Post order로 루트노드를 구하고 출력한다
2. 구해진 root노드를 기점으로 오른쪽과 왼쪽으로 분할한다(Divide)
3. 1-2번을 재귀적으로 반복한다