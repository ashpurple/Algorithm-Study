#include <iostream>
#include <algorithm>
using namespace std;

#define NUM 16 // num
#define INFINITE 987654321

int N, start;
int city[NUM][NUM];
int dp[NUM][1 << NUM]; // cost

int tsp(int cur, int visited){

    if(dp[cur][visited] != -1) // already updated
        return dp[cur][visited];

    if(visited == (1 << N) - 1){ // visit all
        if(city[cur][start] == 0) // no path
            return INFINITE;
        return city[cur][start]; // can go back
    }

    dp[cur][visited] = INFINITE;

    for(int i = 0; i < N; i++){
        if(visited & (1 << i) || city[cur][i] == 0) // visit or no path
            continue;
        
        int past = tsp(i, visited | (1 << i));
        dp[cur][visited] = min(dp[cur][visited], past + city[cur][i]);
    }
    return dp[cur][visited];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> city[i][j];
    }
    
    fill(dp[0], dp[NUM], -1);
    start = 0; // start from 0
    cout << tsp(start, 1 << start);
}