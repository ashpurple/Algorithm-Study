#include<iostream>
using namespace std;
int N;
bool matrix[100][100];
 
void Floyd(){
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (matrix [i][k] && matrix[k][j])
					matrix[i][j] = true; 
			}
		}
	}
}

void printMatrix(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}
}
 
 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for(int i = 0; i < N; i++)
        matrix[i][i] = true;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> matrix[i][j];
    }

	Floyd();
	printMatrix();
}