#include <iostream>
using namespace std;
const int MAX = 100001;
int N, M;
int root[MAX];
long long dist[MAX];

void init(){
    for(int i = 1; i <= N; i++){
        root[i] = i;
        dist[i] = 0;
    }
}
int find(int x){
	if(root[x] == x) return x;
    int updateRoot = find(root[x]); // 반드시 먼저 (거리 업데이트)
	dist[x] += dist[root[x]];
	return root[x] = updateRoot;
}
void Union(int a, int b, int w){
	int aRoot = find(a);
	int bRoot = find(b);
	if(aRoot == bRoot) return;
	root[bRoot] = aRoot;
	dist[bRoot] = dist[a] + w - dist[b];
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        init();
        for (int i = 0; i < M; i++){
            char oper;
            int a, b, w;
            cin >> oper >> a >> b;
            if(oper == '!'){
                cin >> w;
                Union(a, b, w);
            }
            else{
                // 업데이트
                find(a);
                find(b);
                if(root[a] == root[b])
                    cout << dist[b] - dist[a] << '\n';
                else
                    cout << "UNKNOWN" << '\n';
            }
        }
    }
}