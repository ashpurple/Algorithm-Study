# Heap
힙은 주어진 데이터들 중에서 특정 기준에 부합하는 최댓값 혹은 최솟값을 빠르게 찾아낼 수 있는 자료구조이다.<br>
- 힙은 '완전이진트리(Complete Binary Tree)'를 기반으로 한 자료구조이다
- 최대힙의 경우 부모노드의 값이 자식노드의 값보다 크고 최소힙은 그 반대이다.
- 형제노드간의 관계는 존재하지 않는다
- 삽입 시 `O(lg N)` 최대값이나 최소값 검색 시 `O(1)`의 시간복잡도를 가진다
## 작동원리(최대 힙)

![Heapsort-example](https://user-images.githubusercontent.com/75887645/127352702-8fbd7846-d018-4102-866f-b2e7b1d8b5c1.gif)

push
- 트리의 가장 마지막 노드에 값을 넣는다.
- 부모노드와 비교하여 부모노드보다 큰 값은 부모와 swap한다.

![heap-data-structures-3](https://user-images.githubusercontent.com/75887645/127356016-ec65d404-405d-4b20-bbd5-8ccacc12aee0.gif)

pop
- 마지막 노드(leaf)와 루트노드를 swap 한다.
- 루트 노드부터 자식 노드와 비교하여 자식 보다 작다면 더 큰 자식과 swap한다.
- 최대값을 return하고 힙의 크기를 1 감소시킨다.

힙은 단순 배열로 직접 구현 가능하며 이는 [해당 코드](https://github.com/ashpurple/BOJ-Algorithm-Study/blob/main/Algorithm/Heap%20(Priority%20Queue)/heap.cpp)를 참조하면된다.<br>

## Priority Queue (우선순위 큐)
우선순위 큐는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나오는 자료구조를 말한다.<br>
- 우선순위 큐는 힙으로 구현이 되어있다.
- 배열과 연결리스트가 삽입에서 `O(n)` 삭제에서 `O(1)`이 걸리는 반면 우선순위 큐는 둘 모두 `O(lg N)`이 걸린다.
- C++에서는 `#include <queue>` 에서 `priority_queue<int, vector<int>, greater<int>>` (최소힙 예시)가 제공된다.
