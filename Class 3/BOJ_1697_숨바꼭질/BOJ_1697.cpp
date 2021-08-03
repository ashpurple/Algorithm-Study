#include <iostream>
#include <queue>
using namespace std;

void bfs(int);

bool visited[100001];
int target, cnt = 0;
queue <pair<int, int>> q;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start;
    cin >> start >> target;

    if(start == target)
        cout << 0;
    else{
        bfs(start);
        cout << cnt + 1;
    }
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
        int cycle = q.size();

        for(int c = 0; c < cycle; c++){
            int pos = q.front();
            q.pop();

            int move[3];

            move[0] = pos - 1;
            move[1] = pos + 1;
            move[2] = pos << 1;
            
            for(int i = 0; i < 3; i++){
                int x = move[i];

                if(x == target)
                    return;

                if (0 <= x && x <= 100000 && !visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
		cnt++;
	}
}