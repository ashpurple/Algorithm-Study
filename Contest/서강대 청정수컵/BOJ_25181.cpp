#include <iostream>
#include <algorithm>
using namespace std;
struct Info{
    int val;
    int idx;
};

int N;
int ans;
Info arr[100000];
Info newArr[100000];

bool compVal(Info a, Info b){
    return a.val < b.val;
}

bool compIdx(Info a, Info b){
    return a.idx < b.idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        arr[i] = {num, i};
    }
    sort(arr, arr + N, compVal);
    
    int maxCnt = 0;
    int cnt = 0;
    int prev = -1;
    for(int i = 0; i < N; i++){
        if(prev != arr[i].val){
            maxCnt = max(cnt, maxCnt);
            cnt = 1;
            prev = arr[i].val;
        }
        else cnt++; 
    }
    maxCnt = max(cnt, maxCnt);

    if(N < 2 * maxCnt) cout << -1;
    else{
        for(int i = 0; i < N; i++){
            int index = (i + maxCnt) % N;
            newArr[index] = {arr[i].val, arr[index].idx};
        }
        sort(newArr, newArr + N, compIdx);
        for(int i = 0; i < N; i++){
            cout << newArr[i].val << ' ';
        }
    }
}