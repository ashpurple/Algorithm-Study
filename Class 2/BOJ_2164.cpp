#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    queue<int> q;
    cin >> num;

    for(int i = 0; i < num; i++){
        q.push(i+1);
    }
    while(q.size() != 1){
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front();
}