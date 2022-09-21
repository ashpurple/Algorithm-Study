#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int INF = 1000000;
int matrix[201][201];
void printMatrix(int N){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}
}
void Floyd(int N){
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

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    fill(matrix[0], matrix[201], INF);
    for(int i = 1; i <= n; i++) matrix[i][i] = 0;
    for(auto fare : fares){
        matrix[fare[0]][fare[1]] = fare[2];
        matrix[fare[1]][fare[0]] = fare[2];
    }
	Floyd(n);
    
    int minimum = 1987654321;
    for(int i = 1; i <= n; i++){
        int cost = 0;
        cost += matrix[s][i];
        cost += matrix[i][a];
        cost += matrix[i][b];
        minimum = min(minimum, cost);
    }
    answer = minimum;
    return answer;
}