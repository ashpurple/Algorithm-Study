# Union - Find

비행기 번호이하의 게이트로만 도킹이가능하고 불가능할 시 연산을 멈추는 문제이다

알고리즘은 Union-Find를 이용해 간단하게 구현할 수 있다
- find를 이용해 도킹 가능여부를 체크한다 (find()==0 일때 도킹 불가능)
- 도킹이 가능할 때 자신과 자신의 번호 -1의 집합을 Union한다