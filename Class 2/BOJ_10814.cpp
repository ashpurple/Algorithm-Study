#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    pair<int, string> temp;
    vector<pair<int, string>> v;

    for(int i = 0; i < num; i++){
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    stable_sort(v.begin(), v.end(), compare);

    for(int i = 0; i < num; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}