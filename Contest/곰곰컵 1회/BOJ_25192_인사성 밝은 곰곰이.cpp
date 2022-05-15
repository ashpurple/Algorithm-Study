#include <iostream>
#include <set>
using namespace std;
int N;
int cnt;
set <string> name;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    set<string>::iterator iter;
    while(N--){
        string input;
        cin >> input;
        if(input == "ENTER"){
            name.clear();
        }
        else{
            iter = name.find(input);
            if(iter == name.end()){
                name.insert(input);
                cnt++;
            }
        }
    }
    cout << cnt;
}