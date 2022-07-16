#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int prev = -1;
    for(int num : arr){
        if(num != prev){
            answer.push_back(num);
            prev = num;
        }
    }

    return answer;
}