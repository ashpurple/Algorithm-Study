#include <iostream>
using namespace std;
int N;
pair<int,int> people[50];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> people[i].first >> people[i].second;

    for(int i = 0; i < N; i++){
        int rank = 1;
        for(int j = 0; j < N; j++){
            if(people[i].first < people[j].first && people[i].second < people[j].second)
                rank++;
        }
        cout << rank << ' ';
    }
}