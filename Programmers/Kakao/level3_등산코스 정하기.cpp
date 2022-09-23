#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int w; int v;
};
const int SIZE = 50001;
const int INF = 1987654321;
int nodes[SIZE];
int intensity[SIZE];
vector<Edge> graph[SIZE];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
  
  for(auto s: summits) nodes[s] = 2;
  for(auto p: paths) {
    graph[p[0]].push_back({p[2], p[1]});
    graph[p[1]].push_back({p[2], p[0]});
  }

  priority_queue<pair<int,int>> pq;
  for(int i = 1; i <= n; ++i) intensity[i] = INF;
  for(auto g: gates) {
    intensity[g] = -1;
    pq.push({0, g});
  }
    
  int answer = INF;
  int summit = INF;

  while(!pq.empty()) {
    auto [max_intensity, cur_node] = pq.top(); pq.pop();
    
    if(max_intensity > answer) continue;
    if(nodes[cur_node] == 2) {
      if(max_intensity < answer) {
        answer = max_intensity;
        summit = cur_node;
      }
      else if(max_intensity == answer && cur_node < summit) {
        summit = cur_node;
      }
      continue;
    }

    for(auto next: graph[cur_node]) {
      if(intensity[next.v] > max(max_intensity, next.w)) {
        intensity[next.v] = max(max_intensity, next.w);

        pq.push({intensity[next.v], next.v});
      } 
    }
  }

  return {summit, answer};
}