#include <iostream>
#include <queue>
#include <set>
using namespace std;

void bfs();

queue <string> q;
string N;
int K, len;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    q.push(N);
    len = N.length();
    bfs();

    string maxValue = "0";
    while(!q.empty()){
        maxValue = max(maxValue, q.front());
        q.pop();
    }
    if(maxValue[0] == '0')
        cout << "-1";
    else
        cout << maxValue;
}

void bfs(){
	for(int i = 0; i < K; i++){
        set <string> visited;
        int cycle = q.size();
       
        for(int i = 0; i < cycle; i++){
            string num = q.front();
            q.pop();
            if(visited.find(num) != visited.end()) // if visited
                continue;
            
            visited.insert(num);

            for(int j = 0; j < len - 1; j++){
                for(int k = j + 1; k < len; k++){
                    if(j == 0 && num[k] == '0')
                        continue;
                    swap(num[j], num[k]);
                    q.push(num);
                    swap(num[j], num[k]);
                }
            }
        }
    }
}