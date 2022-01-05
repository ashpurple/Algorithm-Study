#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// arr: 초기 배열
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end

/* 초기화 */
long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end)    // 노드가 리프 노드인 경우
        return tree[node] = arr[start];    // 배열의 그 원소를 가져야 함

    int mid = (start + end) / 2;

    // 구간 합을 구하는 경우
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);

    // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.
    // return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

/* 구간합 */
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) { 
        // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우, 
        // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
        return 0;
    }
    if (left <= start && end <= right) {
        // case 2: [start, end]가 [left, right]에 포함
        return tree[node];
    }
    // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

/* 갱신 */
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) // [start, end]가 index가 포함되지 않는 경우
        return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // node size
    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    vector<long long> v(N);
    vector<long long> tree(size);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i]; // node input
	}

    /* Struct */
    init(v, tree, 1, 0, N - 1); // struct tree

    /* Update */
    long long a, b; // update a to b
    long long diff = b - v[a - 1]; // b - a
    v[a - 1] = b; // change node
    update(tree, 1, 0, N - 1, a - 1, diff);

    /* Sum */
    sum(tree, 1, 0, N - 1, a - 1, b - 1);
}