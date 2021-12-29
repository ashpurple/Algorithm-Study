#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	
	if (arr[mid] == target) return mid; // if find
	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
	else return binarySearch(arr, target, mid + 1, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp;
    vector<int> v1, result;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(), v1.end());

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        if(binarySearch(v1, temp, 0, n -1) == -1)
            result.push_back(0);
        else
            result.push_back(1);
    }

    for(int i = 0; i < m; i++)
        cout << result.at(i) << '\n';
}