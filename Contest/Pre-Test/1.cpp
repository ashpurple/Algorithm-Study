#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Data{
    int x;
    int y;
    int size;
    bool operator<(const Data d)const{
        return size > d.size; // descending
    }
};
struct Info{
    int val;
    int day;
};
Info map[300][300];
int T, N, M, D;
long long amount;
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 1; t <= T; t++){
        vector <Data> v;
        cin >> N >> M >> D;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j].val;
                map[i][j].day = 0;
                v.push_back({i, j, map[i][j].val});
            }
        }

        sort(v.begin(), v.end());
        int orderX[90000];
        int orderY[90000];
        int num = 0;
        for(Data data : v){
            orderX[num] = data.x;
            orderY[num] = data.y;
            num++;
        }

        ans = 0;
        int idx = 0;
        int mod = N * M;
        int x, y;
        for(int i = 1; i <= D; i++){
            int oil;
            cin >> oil;

            amount = 0;
            for(int j = 0; j < oil; j++){
                x = orderX[idx];
                y = orderY[idx];
                int val = map[x][y].val + (i - map[x][y].day);
                amount += val - 1;

                map[x][y].val = 1;
                map[x][y].day = i;
                idx++;
                idx %= mod;
            }
            ans += amount * i;
        }
        cout << '#' << t << ' ' << ans << '\n';
    }
}