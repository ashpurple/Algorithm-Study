#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;
    long long end = N - 1;
    long long interval = M + 1;
    long long num = end / interval;
    long long start = end - (interval * num);

    if(0 < start && start <= M) cout << "Can win";
    else cout << "Can't win";
}