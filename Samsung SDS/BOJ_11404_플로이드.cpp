#include<iostream>
#include<vector>
using namespace std;
#define INFINITE 1000000000
int N; // the number of vertex
vector<vector<int>> matrix;
 
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

void printMatrix(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
            if(matrix[i][j] == INFINITE)
                cout << 0 << ' ';
            else
			    cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}
}
 
 int main(){
    int edge_num; // the number of edge
    cin >> N >> edge_num;
    // initialize to infinite
    matrix = vector<vector<int>> (N + 1, vector<int>(N + 1, INFINITE)); 
    
    for(int i = 1; i <= N; i++)
        matrix[i][i] = 0; // initialize

    for(int i = 0; i < edge_num; i++){
        int v, u, edge;
        cin >> v >> u >> edge;
        if(matrix[v][u] > edge)
            matrix[v][u] = edge;
    }

	Floyd();
	printMatrix();
}