#include <iostream>
using namespace std;
 
struct Point{
    long long x;
    long long y;
};
bool intersect;

int CCW(Point A, Point B, Point C){
    long long res = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    if(res < 0) return -1;
    if(res == 0) return 0;
    if(res > 0) return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Point A1, A2, B1, B2;

    cin >> A1.x >> A1.y;
    cin >> A2.x >> A2.y;
    cin >> B1.x >> B1.y;
    cin >> B2.x >> B2.y;

    int ccw1 = CCW(A1, A2, B1);
    int ccw2 = CCW(A1, A2, B2);
    int ccw3 = CCW(B1, B2, A1);
    int ccw4 = CCW(B1, B2, A2);

    if(ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0){
        if(A1.x == B1.x){ // y축 평행
            if(A1.y > A2.y) swap(A1, A2);
            if(B1.y > B2.y) swap(B1, B2);
            if(A1.y <= B2.y && B1.y <= A2.y) intersect = true;

        }
        else{
            if(A1.x > A2.x) swap(A1, A2);
            if(B1.x > B2.x) swap(B1, B2);
            if(A1.x <= B2.x && B1.x <= A2.x) intersect = true;
        }
    }
    else if(ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0){
        intersect = true;
    }

    if(intersect) cout << 1;
    else cout << 0;
}
