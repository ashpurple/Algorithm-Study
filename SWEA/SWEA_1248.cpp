#include <iostream>
using namespace std;
const int MAX_V = 1e4 + 2;
struct Node {
    int parent, left, right;
    void init(){
        parent = left = right = 0;
    }
}tree[MAX_V];

int parent, child, cur;
int TC, V, E, tg1, tg2;
bool check[MAX_V];

void init(){
    for (int i = 0; i < MAX_V; ++i) {
        tree[i].init();
        check[i] = false;
    }
}

void input(){
    cin >> V >> E >> tg1 >> tg2;

    for (int i = 0; i < E; i++) {
        cin >> parent >> child;
        if (tree[parent].left == 0)
            tree[parent].left = child;
        else 
            tree[parent].right = child;
        tree[child].parent = parent;
    }
}

int DFS(int cur) {
    int ans = 1;

    if (tree[cur].left != 0)
        ans += DFS(tree[cur].left);
    if (tree[cur].right != 0)
        ans += DFS(tree[cur].right);
    return ans;
}

int main() {
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        init();
        input();

        cur = tree[tg1].parent;
        while (true) {
            check[cur] = true;
            if (cur == 1) break;
            cur = tree[cur].parent;
        }

        cur = tree[tg2].parent;
        while (true) {
            if (check[cur]) {
                cout << "#" << tc<< ' ' << cur << ' ' << DFS(cur) << '\n';
                break;
            }
            cur = tree[cur].parent;
        }
    }
}