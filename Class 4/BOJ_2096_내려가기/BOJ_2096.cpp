#include <iostream>
#include <algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxMap[3];
    int minMap[3];
    int input[3];
    int N;
    
    cin >> N;

    cin >> maxMap[0] >> maxMap[1] >> maxMap[2];
    minMap[0] = maxMap[0];
    minMap[1] = maxMap[1];
    minMap[2] = maxMap[2];

    for (int i = 1; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];

        int cache1 = maxMap[0];
        int cache2 = maxMap[1];
        int cache3 = maxMap[2];

        maxMap[0] = max(cache1, cache2) + input[0];
        maxMap[1] = max(cache1, max(cache2, cache3)) + input[1];
        maxMap[2] = max(cache2, cache3) + input[2];

        cache1 = minMap[0];
        cache2 = minMap[1];
        cache3 = minMap[2];

        minMap[0] = min(cache1, cache2) + input[0];
        minMap[1] = min(cache1, min(cache2, cache3)) + input[1];
        minMap[2] = min(cache2, cache3) + input[2];
	}
    
    int maxValue =  max(maxMap[0], max(maxMap[1], maxMap[2]));
    int minValue =  min(minMap[0], min(minMap[1], minMap[2]));
    cout << maxValue << " " << minValue;
}