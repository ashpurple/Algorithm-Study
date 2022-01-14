# 인덱스 트리

inversion counting 문제입니다<br>
index tree를 이용하여 풀이하였고 원리는 다음과 같습니다<br>
입력: A[i] = input, B[input] = i<br>
=> 이를 이용하면 `target = B[A[i]]` 를 활용해 해당 인덱스를 타겟값으로 설정할 수 있습니다<br>
인덱스 트리의 구간합을 이용해 target 보다 큰 visit 처리된(1) 리프노드의 합을 정답에 더해줍니다<br>
=> target노드 보다 큰 값의 visit개수는 꼬인 점의 개수를 의미합니다<br>
update로 target 노드를 1로 만들어주며 반복합니다
