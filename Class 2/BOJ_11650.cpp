#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    pair<int, int> temp;
    vector<pair<int, int>> v;

    for(int i = 0; i < num; i++){
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < num; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}