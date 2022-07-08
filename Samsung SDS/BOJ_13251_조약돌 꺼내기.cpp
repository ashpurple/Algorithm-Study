#include <iostream>
using namespace std;
int num[51];
int M, K;
int sum;
double ans;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
	for (int i = 0; i < M; i++){
		cin>> num[i];
		sum += num[i];
	}
	cin >> K;
	for (int i = 0; i < M; i++){
		double mul = 1.0;
		if (K > num[i])	continue;
		for (int j = 0; j < K ; j++){
			mul *= (num[i] - j);
		}
		ans += mul;
	}
    double denom = 1;
    for (int i = 0; i < K ; i++)
        denom *= (sum - i);

	cout << fixed;
	cout.precision(18);
	cout << ans / denom;
}
