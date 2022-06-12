#include <iostream>
using namespace std;
int T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int t = 0; t < T; t++){
        int N;
        int arr[50000];

        cin >> N;
        for(int i = 0; i < N; i++) cin >> arr[i];
        

        bool flag = true;
      
        for(int i = 0; i < N; i++){
            arr[i] = min(arr[i], N + 1 - arr[i]);

            if(i == 0) continue;
            if(arr[i - 1] > arr[i]){
                arr[i] = N + 1 - arr[i];
                if(arr[i - 1] > arr[i]) flag = false;
            }
        }

        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}