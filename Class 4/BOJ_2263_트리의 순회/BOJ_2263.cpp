#include <iostream>
#define MAX 100001
using namespace std;

int inOrder[MAX];
int postOrder[MAX];
int idx[MAX];
 
void preOrder(int inBegin, int inEnd, int postBegin, int postEnd){
        if (inBegin > inEnd || postBegin > postEnd) // terminate
                 return;
   
        int root = postOrder[postEnd];
        cout << root << " ";

        // Left
        preOrder(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);
        // Right
        preOrder(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);
}

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int N;

        cin >> N;
        for (int i = 0; i < N; i++)
                 cin >> inOrder[i];

        for (int i = 0; i < N; i++)
                 cin >> postOrder[i];

        for (int i = 0; i < N; i++)
                 idx[inOrder[i]] = i;

        preOrder(0, N - 1, 0, N - 1);
        cout << '\n';

        return 0;
}