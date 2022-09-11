#include <string>
#include <vector>
using namespace std;
bool m1[16][16];
bool m2[16][16];
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int idx = 0;
    for(int num : arr1){
        for(int i = n - 1; 0 <= i; i--){
            m1[idx][i] = num & 1;
            num >>= 1;
        }
        idx++;
    }
    idx = 0;
    for(int num : arr2){
        for(int i = n - 1; 0 <= i; i--){
            m2[idx][i] = num & 1;
            num >>= 1;
        }
        idx++;
    }
    
    for(int i = 0; i < n; i++){
        string str = "";
        for(int j = 0; j < n; j++){
            if(m1[i][j] || m2[i][j]) str += '#';
            else str += ' ';
        }
        answer.push_back(str);
    }
    
    return answer;
}