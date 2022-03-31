#include <iostream>
#include <map>
using namespace std;
int T, N;
string name, kind;

int combi(map<string,int> m){
    int res = 1;
    for(auto it = m.begin(); it != m.end(); it++){
        res = res * (it->second + 1);
    }
    return res - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N;
        map<string, int> fashion;
        for(int i = 0; i < N; i++){
            cin >> name >> kind;
            fashion[kind]++;
        }
        cout << combi(fashion) << '\n';
    }
}