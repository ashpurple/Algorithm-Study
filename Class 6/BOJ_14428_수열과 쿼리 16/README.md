# 인덱스 트리(세그먼트 트리)

정석적인 풀이는 세그트리를 이용해 min index를 구하는 문제지만 인덱스트리를 변형해 풀이했다<br>
<알고리즘>
- 값과 인덱스를 가진 구조체를 선언 후 인덱스트리도 해당 구조체 타입으로 선언했다
- operator와 min값을 반환해주는 cmp함수를 만들어 인덱스트리를 구현했다
=> min(a, b)는 구조체에서 정상작동하지 않았다

따라서 각 non-leaf node에는 leaf node의 최소값과 인덱스가 들어있다