#include <iostream>
#include <vector>
using namespace std;
 
int N, maxValue, idx;
int num[1000000];
int dp[1000000];
vector<int> v;
vector<int> res;

void lis(){
    v.push_back(0);
    for(int i = 0; i < N; i++){
        if(v.back() < num[i]){
            v.push_back(num[i]);
            dp[i] = v.size() - 1;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), num[i]);
            *it = num[i];
            dp[i] = it - v.begin();
        }
        if(dp[i] > maxValue){
            maxValue = dp[i];
            idx = i; // store max lis
        }
    }

    res.push_back(num[idx]);
    for(int i = idx - 1; i >=0; i--){
        if(dp[i] == dp[idx] - 1 && num[i] < num[idx]){
            res.push_back(num[i]);
            idx = i;
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

    cout << res.size() << '\n';
    while(!res.empty()){ // print reverse order
        cout << res.back() << ' ';
        res.pop_back();
    }
}
