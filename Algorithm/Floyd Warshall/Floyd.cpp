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
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}
}
 
 int main(){
    /*
    input format
    4 9 -> V_num, E_num
    1 2 5 -> v, u, edge
    1 3 7
    2 1 4
    2 3 12
    2 4 13
    3 1 6
    3 4 20
    4 2 9
    4 3 8
    */

    int edge_num; // the number of edge
    cin >> N >> edge_num;
    // initialize to infinite
    matrix = vector<vector<int>> (N + 1, vector<int>(N + 1, INFINITE)); 
    
    for(int i = 1; i <= N; i++)
        matrix[i][i] = 0; // initialize

    for(int i = 0; i < edge_num; i++){
        int v, u, edge;
        cin >> v >> u >> edge;
        matrix[v][u] = edge;
    }

    printMatrix(); // before
	Floyd();
	printMatrix(); // after
}