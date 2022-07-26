#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 100005;
int n;
int d[MAXN],p[MAXN][23];
bool visited[MAXN];
vector<vector<int>> Node;

void init(){
    memset(visited, 0, sizeof(visited));
    memset(d, 0, sizeof(d));
    memset(p, 0, sizeof(p));
    Node.clear();
}
 
void sparse(){
    for(int i=1;i<=20;i++){
        for(int j=0;j<n;j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
}
 
int lca(int x,int y){
    if(d[y]>d[x]) swap(x,y);
    for(int i=19;i>=0;i--){
        if((d[x]-d[y])>=(1<<i)) x = p[x][i];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(p[x][i] != p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}
 
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        init();
        cin >> n;
        Node.resize(n + 3);
 
        for(int i = 1; i < n; i++){
            int x;
            cin >> x;
            Node[x-1].push_back(i);
        }
        for(int i = 0; i < n; i++) sort(Node[i].begin(), Node[i].end());
 
        queue<pair<int,int>> dq;
        dq.push({0, 0});
        visited[0] = true;
 
        while(!dq.empty()){
            int now = dq.front().first;
            int depth = dq.front().second;
            dq.pop();
            d[now]=depth;
 
            for(int i = 0; i < Node[now].size(); i++){
                int next = Node[now][i];
                if(!visited[next]){
                    visited[next]=true;
                    p[next][0]=now;
                    dq.push({next,depth+1});
                }
            }
        }
       
        sparse();
 
        long long ans = 0;
        memset(visited, 0, sizeof(visited));
        vector<int> vt;
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int now = q.front(); q.pop();
            vt.push_back(now);
            for(int i=0;i<Node[now].size();i++){
                int next = Node[now][i];
                if(!visited[next]){
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
        for(int i = 0; i < n-1; i++){
            int LCA = lca(vt[i],vt[i+1]);
            long long a = d[vt[i]] - d[LCA];
            long long b = d[vt[i+1]] - d[LCA];
            ans += a; ans += b;
        }
        cout << '#' << t << ' ' << ans  << '\n';
    }
}