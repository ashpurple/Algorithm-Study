#include <iostream>
using namespace std;

int root[1000001];

int find(int x) {
    if (root[x] == x) {
        return x;
    } 
    else {
        // "경로 압축(Path Compression)"
        return root[x] = find(root[x]); 
    }
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    root[y] = x;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int op, x, y;
    cin >> N >> M;
    
    for (int i = 0; i <= N; i++){
      root[i] = i;
    }

    for(int i = 0; i < M; i++){
        cin >> op >> x >> y;
        if(op == 0){
            Union(x, y);
        }
        else if(op == 1){
            if(find(x) == find(y))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
 
    return 0;
}