#include <iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    map<string, int> pocket_string;
    string pocket_int[100000];

    for(int i = 1; i <= N; i++){
        string name;
        cin >> name;
        pocket_string.insert(pair<string, int>(name, i));
        pocket_int[i] = name;
    }

    for(int i = 1; i <= M; i++){
        string prob;
        cin >> prob;
        if(isdigit(prob[0])){
            int index = stoi(prob);
            cout << pocket_int[index] << '\n';
        }
        else{
            cout << pocket_string[prob] << '\n';
        }

    }

}