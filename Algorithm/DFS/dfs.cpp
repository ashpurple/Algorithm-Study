#include <vector>
using namespace std;

bool visited[101]; 
vector<int> node[101]; // N = node의 개수, node [N + 1]

void dfs(int parent){
	visited[parent] = true;
	for (int i = 0; i < node[parent].size(); i++){
		int child = node[parent][i];
		if (!visited[child])
            dfs(child);
	}
}