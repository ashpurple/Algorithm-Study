#include <iostream>
#include <vector>
using namespace std;
struct Data{
    int h;
    int num;
};

int N;
long long cnt;
vector<Data> stack;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;

        Data data;
        bool isSame = false;
        while(!stack.empty() && stack.back().h <= input){
            data = stack.back();
            if(data.h == input) isSame = true;
            cnt += data.num;
            stack.pop_back();
        }
        if(!stack.empty()) cnt++;
        if(isSame) stack.push_back({input, data.num + 1});
        else stack.push_back({input, 1});
    }
    cout << cnt;
    
}