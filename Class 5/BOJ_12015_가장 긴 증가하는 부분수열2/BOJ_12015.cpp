#include <iostream>
#include <vector>
using namespace std;
 
int N;
int num[1000000];
vector<int> v;

void lis(){
    v.push_back(0);
    for(int i = 0; i < N; i++){
        if(v.back() < num[i])
            v.push_back(num[i]);
        else{
            auto it = lower_bound(v.begin(), v.end(), num[i]);
            *it = num[i];
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    lis();
    cout << v.size() - 1;
}
