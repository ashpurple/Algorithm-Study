# 수학 (기하학)

[선분 교차 알고리즘]

CCW 함수를 이용하면 세점의 방향성을 구할 수 있다

CCW를 네번사용하면 선분 두개의 교차성을 알 수 있다
```C++
int ccw1 = CCW(A1, A2, B1);
int ccw2 = CCW(A1, A2, B2);
int ccw3 = CCW(B1, B2, A1);
int ccw4 = CCW(B1, B2, A2);

if(ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0){
        intersect = true;
    }
```
하지만 네점이 일직선에 위에 있는 경우는 각점의 상대위치도 고려하여 판단해야한다

