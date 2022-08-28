#include<iostream>
#include<queue>
using namespace std;
const int MAX = 1987654321;
struct Car{
    int num;
    int sec;
};
int N;
int ans[200000];
queue<Car> q[4];

bool isEmpty(){
    for(int i = 0; i < 4; i++){
        if(!q[i].empty()) return false;
    }
    return true;
}

bool isDeadlock(int time){
    for(int i = 0; i < 4; i++){
        if(q[i].empty()) return false;
        if(q[i].front().sec > time) return false;
    }
    return true;
}

bool simulate(int time){
    bool canPass[4] = {false};
    for(int i = 0; i < 4; i++){
        if(q[i].empty()) continue;
        if(q[i].front().sec > time) continue; // 아직 미도착 
        // 옆 교차로 확인
        int right = (i + 3) % 4;
        if(q[right].empty()) canPass[i] = true;
        else if(q[right].front().sec > time) canPass[i] = true;
    }
    bool isMove = false;
    for(int i = 0; i < 4; i++){
        if(canPass[i]){
            isMove = true; // 움직임 판단
            int num = q[i].front().num;
            ans[num] = time;
            q[i].pop();
        }
    }
    return isMove;
}

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    int time = 0;
    for(int i = 0; i < N; i++){
        int t;
        char w;
        cin >> t >> w;
        if(i == 0) time = t;
        q[w - 'A'].push({i, t});
    }

    while(true){
        if(isEmpty() || isDeadlock(time)) break;
        if(simulate(time)) time++;
        else{ // 변화 없으면 시간 최적화
            int minTime = MAX;
            for(int i = 0; i < 4; i++){
                if(!q[i].empty()) minTime = min(q[i].front().sec, minTime);
            }
            time = minTime;
        }
    }

    for(int i = 0; i < 4; i++){ // 교착 상태 처리
        while(!q[i].empty()){
            int num = q[i].front().num;
            ans[num] = -1;
            q[i].pop();
        }
    }

    for(int i = 0; i < N; i++) cout << ans[i] << '\n';

	return 0;
}