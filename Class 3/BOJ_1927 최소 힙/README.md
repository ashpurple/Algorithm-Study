# Priority Queue (Heap)

최소 힙을 구하는 문제이다 <br>
C++에서는 priority queue(우선순위 큐)가 heap으로 구현되어있기 때문에<br>
우선순위 큐의 top(), push(), pop(), empty() 함수를 이용하여 간단하게 구현하였다.<br>

단 최소 힙의 경우 내림차순 정렬이 되어있어야 하기 때문에<br>
`priority_queue<int, vector<int>, greater<int>>` 와 같이 세번째 인자를 수정해주었다.