#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[10];
    set<int> s;
    for(int i = 0; i < 10; i++){
        int num;
        cin >> num;
        s.insert(num % 42);
    };
    cout << s.size();
    
}