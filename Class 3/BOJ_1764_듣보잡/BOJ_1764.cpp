#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<string> s1;
set<string> s2;
set<string> s3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    string name;

    for(int i = 0; i < N; i++){
        cin >> name;
        s1.insert(name);
    }

    for(int i = 0; i < M; i++){
        cin >> name;
        s2.insert(name);
    }

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));

    cout << s3.size() << '\n';
    for(set<string>::iterator it = s3.begin(); it != s3.end(); it++){
        cout << *it << '\n';
    }

}