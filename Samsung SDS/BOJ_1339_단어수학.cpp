#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<string> word;
map<char, int> result;

void calculate(){
    for(string str: word){
        int size = str.size();
        for(int i = 0; i < size; i++){
            char c = str[i];
            int cnt = 1;
            for(int j = 0; j < size - 1 - i; j++){
                cnt *= 10; 
            }
            if(result.find(c) == result.end()){
                result.insert(make_pair(c, cnt));
            }
            else{
                int value = result[c];
                value += cnt;
                result.erase(c);
                result.insert(make_pair(c, value));
            }
        }
    }
}

bool cmp(const pair<char,int>& a, const pair<char,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        word.push_back(input);
    }
    calculate();

    vector<pair<char, int>> vec(result.begin(), result.end());
    sort(vec.begin(), vec.end(), cmp);

    int sum = 0;
    int num = 9;
    for(pair<char,int> i : vec){
        int temp = i.second;
        sum += temp * num;
        num--;
    }
    cout << sum;
}

