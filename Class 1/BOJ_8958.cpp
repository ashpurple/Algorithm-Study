#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    string prob;

    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> prob;

        int score = 0, totalScore = 0;
        for(int j = 0; j < prob.size(); j++){
            if(prob[j]=='O'){
                score++;
                totalScore += score;
            }
            else{
                score = 0;
            }

        }
        cout << totalScore << '\n';
    }
}