#include <string>
#include <vector>
#include <iostream>

using namespace std;
int map[100][100];

int rotate(int sR, int sC,int eR,int eC){
    sR--; sC--; eR--; eC--;
    int minimum = 1987654321;
    int start = map[sR][eC];
    for (int i = eC; sC < i; i--){
        map[sR][i] = map[sR][i - 1];
        minimum = min(minimum, map[sR][i]);
    }
    for (int i = sR; i < eR; i++){
        map[i][sC] = map[i + 1][sC];
        minimum = min(minimum, map[i][sC]);
    }
    for (int i = sC; i < eC; i++){
        map[eR][i] = map[eR][i + 1];
        minimum = min(minimum, map[eR][i]);
    }
    for (int i = eR; sR + 1 < i; i--){
        map[i][eC] = map[i - 1][eC];
        minimum = min(minimum, map[i][eC]);
    }
    map[sR + 1][eC] = start;
    minimum = min(minimum, start);
    return minimum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            map[i][j] = num++;
        }
    }
    
    for(auto query : queries){
        answer.push_back(rotate(query[0], query[1], query[2], query[3]));
    }
    
    return answer;
}