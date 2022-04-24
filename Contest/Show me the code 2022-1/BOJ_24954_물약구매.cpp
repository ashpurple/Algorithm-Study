#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct DISCOUNT{
    int num;
    int price;
};

int N;
vector<DISCOUNT> disList[11];
bool visited[11];
int res = 1987654321;

void discount(int num, int arr[11]){
    for(DISCOUNT dis : disList[num]){
        arr[dis.num] -= dis.price;
        if(arr[dis.num] <= 0) arr[dis.num] = 1;
    }
    
}

void dfs(int cnt, int price[11], int sum) { // nPm
	if (cnt == N) {
        //cout << "\n";
		res = min(res, sum);
        return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
            sum += price[i];
            int temp[11];

            copy(price, price + 11, temp);
            discount(i, temp);

			visited[i] = true;
            //cout << i << ' ';
			dfs(cnt + 1, temp, sum);
			visited[i] = false;
            sum -= price[i];
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int arr[11];
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        for(int j = 0; j < num; j++){
            int a, b;
            cin >> a >> b;
            disList[i].push_back({a, b});
        }
    }
    dfs(0, arr, 0);
    cout << res;
   
}