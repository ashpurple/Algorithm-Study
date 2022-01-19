#include <iostream>
#include <vector>
using namespace std;

#define SIZE 100001 // Vertex + 1

struct Data {
    int vertex;
    int weight;
    Data(int vertex, int weight) : vertex(vertex), weight(weight) {};
};

vector<Data> edge[SIZE]; // 2 dimension
bool isVisited[SIZE];

int N;
int maxDist = 0;
int maxVertex; 

void init(){
    maxDist = 0;
    for(int i = 1; i <= N; i++){
        isVisited[i] = false;
    }
}

void dfs(int start, int dist){
    if(isVisited[start]) return;
    isVisited[start] = true;

    if(maxDist < dist){
            maxDist = dist;
            maxVertex = start;
    }

    for(int i = 0; i < edge[start].size(); i++){
        Data data = edge[start][i];
        int v = data.vertex;
        int w = data.weight;
        dfs(v, dist + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v, w;
    cin >> N;
    
    /* input */
    for (int i = 1; i < N; i++) {
        cin >> u >> v >> w;
        edge[u].push_back(Data(v, w));
        edge[v].push_back(Data(u, w));
    }

    init();
    dfs(1, 0); // from first vertex
    init(); 
    dfs(maxVertex, 0); // from most deep vertex
    
    cout << maxDist;
}