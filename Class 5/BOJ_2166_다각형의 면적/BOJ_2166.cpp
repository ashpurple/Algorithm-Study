#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point{
    long double x;
    long double y;
};

vector<Point> points;
int N;

long double crossProduct(Point init, Point a, Point b){
    long double res;
    res = (a.x - init.x) * (b.y - init.y) - (a.y - init.y) * (b.x - init.x);
    return res / 2;
}

long double calcualte(){
    long double area = 0;
    Point init = points[0];

    for(int i = 1; i < N - 1; i++){
        area += crossProduct(init, points[i], points[i + 1]);
    }
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Point input;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input.x >> input.y;
        points.push_back(input);
    }

    long double res = abs(calcualte());
    cout << fixed;
    cout.precision(1);
    cout << res;
}