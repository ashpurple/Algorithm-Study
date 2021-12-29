#include <queue>
#include <vector>
using namespace std;

/* Recursive */
int binarySearch(vector<int>& arr, int target, int start, int end) {
	if (start > end) return -1;
	
	int mid = (start + end) / 2;
	
	if (arr[mid] == target) 
		return mid; // if find
	else if (arr[mid] > target) 
		return binarySearch(arr, target, start, mid - 1);
	else 
		return binarySearch(arr, target, mid + 1, end);
}

/* Loop */
int binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) 
			return mid;
		else if (arr[mid] > target) 
			end = mid + 1;
		else 
			start = mid + 1;
	}
	return -1;
}