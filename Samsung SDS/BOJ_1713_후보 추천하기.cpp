#include <iostream>
using namespace std;

int vote[101], time[101];
int candidate, N;
int photo = 0;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> candidate;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int student;
        cin >> student;

        if(vote[student]>0)
            vote[student]++;
        else{
            if(photo < candidate){
                vote[student]++;
                photo++;
                time[student] = i;
            }
            else{
                int min = 10000;
                int index;
                for(int j = 1; j <= 100; j++){
                    if(vote[j] == 0)
                        continue;
                    if(vote[j] < min){
                        index = j;
                        min = vote[j];
                    }
                    else if(vote[j] == min){
                        if(time[j] < time[index])
                            index = j;
                    }
                }
                vote[student]++;
                time[student] = i;
                vote[index] = 0;
                time[index] = 0;
            }
        }
    }
    for(int i = 1; i <= 100; i++){
        if(vote[i])
            cout << i << ' ';
    }
}

