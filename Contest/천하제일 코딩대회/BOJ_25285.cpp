#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        double height, weight;
        cin >> height >> weight;
        double h = height / 100;
        double BMI = weight / (h * h);
                
        int level;

        if(height < 140.1){
            level = 6;
        }
        else if(140.1 <= height && height < 146){
            level = 5;
        }
        else if(146 <= height && height < 159){
            level = 4;
        }
        else if(159 <= height && height < 161){
            if(16 <= BMI && BMI < 35) level = 3;
            else level = 4;
        }
        else if(161 <= height && height < 204){
            if(20 <= BMI && BMI < 25) level = 1;
            else if(18.5 <= BMI && BMI < 20) level = 2;
            else if(25 <= BMI && BMI < 30) level = 2;
            else if(16 <= BMI && BMI < 18.5) level = 3;
            else if(30 <= BMI && BMI < 35) level = 3;
            else level = 4;
        }
        else level = 4;
        
        cout << level << '\n';
    }


}