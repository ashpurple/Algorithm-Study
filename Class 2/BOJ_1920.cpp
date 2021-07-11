#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp;
    vector<int> v1, result;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v1.push_back(temp);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        if(find(v1.begin(), v1.end(), temp) == v1.end())
            result.push_back(0);
        else
            result.push_back(1);
    }

    for(int i = 0; i < m; i++)
        cout << result.at(i) << '\n';
}