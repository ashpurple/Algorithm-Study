# BFS

BFS를 활용해 그래프의 Depth를 구하는 문제이다.<br>
초기에 익은 토마토가 여러개 주어질 수 있기에 root node는 여러개일 수 있다.<br>
따라서 초기 node들의 좌표를 queue에 pair 형식으로 저장한다.<br>

<b>하나의 cycle은 초기 queue의 사이즈 만큼 반복하며 cycle은 depth를 의미한다.</b><br>
따라서 한번의 cycle마다 day 값은 1씩 증가한다.