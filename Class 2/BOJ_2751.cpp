#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp;
    vector<int> vec;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());

    for(int i = 0; i < num; i++)
        cout << vec[i] << '\n';
}