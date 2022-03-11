#include <iostream>
#include <map>
using namespace std;

int N, M;
map <string, string> DB;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string site, pw;
    for(int i = 0; i < N; i++){
        cin >> site >> pw;
        DB[site] = pw;
    }
    for(int i = 0; i < M; i++){
        cin >> site;
        cout << DB[site] << '\n';
    }
}