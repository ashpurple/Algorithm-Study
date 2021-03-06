# BinarySearch (이진 탐색)
![binary-search-sequence-search](https://user-images.githubusercontent.com/75887645/147660218-6de186d3-bb34-4ab9-bccf-6a214223128c.gif)


<원리>
1. 탐색하고자 하는 범위의 시작점, 끝점, 중간점을 사용한다. <br>
2. 찾으려는 값과 중간점 데이터를 비교한다. <br>
3. 값이 중간점보다 작으면 중간점을 끝점으로 값이 중간점 보다 크면 중간점을 시작점으로 변경한다. <br>
4. 시작점과 끝점값이 역전되면 탐색을 중지하고 -1을 리턴한다.

<장점>
- 정렬되어 있는 정적 배열에서 효율적이다. `O(lg N)`

<단점>
- 배열 내부의 데이터가 모두 정렬되어 있어야한다.
- 따라서 정렬되어있지 않은 동적 배열에선 이진탐색이 적합하지 않을 수 있다.
