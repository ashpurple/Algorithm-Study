#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> num;

    for(int t = 0; t < num; t++){
        int H, W, N;
        cin >> H >> W >> N;

        int floor = N % H;
        int number = (N / H) + 1;
        
        if(floor == 0){
            floor = H;
            number -=1;
        }
        cout << floor;
        cout.width(2);
        cout.fill('0');
        cout << number << '\n';
    }
}