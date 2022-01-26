#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

int CCW(Point A, Point B, Point C){
   return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

int main(){
    Point P1, P2, P3;
    int result = CCW(P1, P2, P3);
 
    if (result == 0) {
        cout << "직선: "<<result<<"\n";
    }
    else if (result > 0) {
        cout << "반시계방향: " << result << "\n";
    }
    else {
        cout << "시계방향: " << result << "\n";
    }
    // 삼각형의 넓이
    cout << abs(result) / 2;
}
