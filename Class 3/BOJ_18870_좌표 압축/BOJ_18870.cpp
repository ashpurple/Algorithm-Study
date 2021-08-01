#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    vector<int> v, sorted;
    map<int, int> m;

    cin >> N;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for(int i = 0; i < sorted.size(); i++){
        m[sorted[i]] = i;
    }

    for(int i = 0; i < N; i++){
        cout << m[v[i]]<< " " ;
    }
    
}