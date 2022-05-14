# 구현, 시뮬레이션

이중 구조체를 사용하여 자료구조를 만들었고 가능한 경우의 수마다 재귀로 simulate 함수를 호출하였다<br>
```C++
struct Pipe{
    Loc a;
    Loc b;
    int status; // 0 가로 1 세로 2 대각선
};
```
파이프 이동에서 a쪽은 항상 b쪽으로 이동하며 b쪽만 상황에 맞추어 값을 변환시켰다<br>
모든 simulation에서 b가 끝에 도달하면 cnt값을 증가시켰고 유효하지 않은 경우들은 isValid 에 의해 소멸된다<br>
