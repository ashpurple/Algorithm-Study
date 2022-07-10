#include <vector>
using namespace std;
int map[500][500];
bool visited[500][500];

void makeMap(int x, int y, bool h, int N, int num){
    if(num == N * N){
        map[x][y] = num;
        return;
    }
    map[x][y] = num++;
    
    visited[x][y] = true;
    if(x == 0 || y == 0){
        if(h) makeMap(x, y + 1, !h, N, num);
        else makeMap(x + 1, y, !h, N, num);
    }
    else if(x == y){
        if(h) makeMap(x, y - 1, !h, N, num);
        else makeMap(x - 1, y, !h, N, num);
    }
    else{
        if(h){
            if(!visited[x + 1][y]) makeMap(x + 1, y, h, N, num);
            else if(!visited[x - 1][y]) makeMap(x - 1, y, h, N, num);
            else makeMap(x, y + 1, h, N, num);
        }
        else{
            if(!visited[x][y + 1]) makeMap(x, y + 1, h, N, num);
            else if(!visited[x][y - 1]) makeMap(x, y - 1, h, N, num);
            else makeMap(x + 1, y, h, N, num);
        }
    }
}

vector<vector<int>> solution(int n, bool horizontal) {
    vector<vector<int>> answer;

    makeMap(0, 0, horizontal, n, 1);
    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = 0; j < n; j++){
            v.push_back(map[i][j]);
        }
        answer.push_back(v);
    }

    return answer;
}