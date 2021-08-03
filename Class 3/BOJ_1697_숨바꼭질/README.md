# BFS

BFS를 활용해 그래프의 Depth를 구하는 문제이다.<br>
각 이동 마다 3가지 경우의 수가 가능하기 때문에 중복연산은 visited로 걸러주었고<br>
이동 값이 boundary 내에 있을 때만 queue에 push 해주었다<br>
queue에 값을 넣기전 값이 target과 일치할 경우 함수를 종료 해주었다<br>

<b>하나의 cycle은 초기 queue의 사이즈 만큼 반복하며 cycle은 depth를 의미한다.</b><br>
따라서 한번의 cycle마다 cnt는 1씩 증가한다.