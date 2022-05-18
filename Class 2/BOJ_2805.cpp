#include <iostream>
using namespace std;
int N, M;
int tree[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }
    
    int start = 0;
    int end = 2000000000;
    int res;

    while(start <= end){
        long long sum = 0;
        int mid = (start + end) / 2;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid) sum += tree[i] - mid;
        }
        if(sum < M) end = mid - 1;
        else{
            res = mid;
            start = mid + 1;
        }
    }
    cout << res;
}