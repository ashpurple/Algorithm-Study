#include<iostream>
#include<limits.h>
#include<map>
using namespace std;
int N;
long long B;
map<int, int> m;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		m[num]++;
	}

	long long cost = 0;
	long long target = 0;
	long long l = 0;
	long long r = INT_MAX;
	while(l + 1 < r){
		cost = 0;
		target = (l + r) / 2;
		bool flag = true;

		for(auto iter = m.begin(); iter != m.end(); iter++){
			int num = iter->first;
			if(num < target){
				long long square = (target - num) * (target - num);
				cost += (square * iter->second);
			} else break;
			if(cost > B){
				flag = false;
				break;
			}
		}
		
		if(flag) l = target;
		else r = target;
	}

	cout << l;

	return 0;
}