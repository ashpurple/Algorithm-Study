#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string x, string y) {
    int i = 0;
    if(x.length() == y.length())
    {
        for(int i = 0; i < x.length(); i++)
        {
            if(x[i] != y[i])
                return x[i] < y[i];
        }
    }
    return x.length() < y.length();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    string temp;
    cin >> num;
    vector<string> words;
    for(int i = 0; i < num; i++){
        cin >> temp;
        words.push_back(temp);
    }

    sort(words.begin(), words.end(), compare);

    for(int i = 0; i < num - 1; i++){
        if(words[i] != words[i + 1])
            cout << words[i] << '\n';
    }
    cout << words[num - 1];
}