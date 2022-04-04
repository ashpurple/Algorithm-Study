#include <iostream>
using namespace std;
int N, M;
bool flag;
string S;

int isMatch(int start){
    if(M < start + N * 2 + 1) return M;
    for(int i = 0; i < N * 2 + 1; i++){
        if((i & 1) == 0){ // even
            if(S[start + i] == 'O') return start + i + 1;
        }
        else if(i & 1){ // odd
            if(S[start + i] == 'I') return start + i;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;
    int i = 0;
    int loc;
    int cnt = 0;
    while(i < M){
        if(flag){ // continous
            if(i + 1 == M) break;
            if(S[i] == 'O' && S[i + 1] == 'I'){
                cnt++;
                i += 2;
                continue;
            }
            flag = false;
        }

        loc = isMatch(i);
        if(loc == -1){
            i = i + (N * 2) + 1;
            flag = true;
            cnt++;
        }
        else{
            i = loc;
        }
    }
    cout << cnt;
    
}