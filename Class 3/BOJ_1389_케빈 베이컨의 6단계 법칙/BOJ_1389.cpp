#include <iostream>
using namespace std;
const int MAX = 987654321;
int N, M;
int matrix[101][101];

void init(){
    for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			matrix[i][j] = MAX;
		}
	}
}

void Floyd(){
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
                int temp = matrix[i][k] + matrix[k][j];
				if (temp < matrix[i][j])
					matrix[i][j] = temp; 
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    init();
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    Floyd();

    int minSum = MAX;
    int ans;
    for (int i = 1; i <= N; i++){
        int sum = 0;
		for (int j = 1; j <= N; j++){
			if(i == j) continue;
            sum += matrix[i][j];
		}
        if(minSum > sum){
            minSum = sum;
            ans = i;
        }
	}
    cout << ans;
    
}