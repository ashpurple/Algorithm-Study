#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Loc{
    int x; int y;
    const bool operator<(const Loc &loc) const{
        if(x == loc.x) return y < loc.y;
        return x < loc.x;
    }
};
int N;
int cnt;
vector<Loc> v;
set<Loc> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int w, h;
    cin >> w >> h;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        s.insert({x, y});
    }

    for(int i = 0; i < N; i++){
        bool flag = true;
        if(s.find({w + v[i].x, v[i].y}) == s.end()) flag = false;
        if(s.find({v[i].x, h + v[i].y}) == s.end()) flag = false;
        if(s.find({w + v[i].x, h + v[i].y}) == s.end()) flag = false;
        if(flag) cnt++;
    }
    cout << cnt;
}