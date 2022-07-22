#include<iostream>
using namespace std;
struct Node{
    char key;
    int child[2];
};
string ans;
int T, N;
Node node[101];

void inorder(int num){
    if(node[num].child[0] != -1)
        inorder(node[num].child[0]);
    ans += node[num].key;
    if(node[num].child[1] != -1)
        inorder(node[num].child[1]);
}

int main(int argc, char** argv){
	for(int t = 1; t <= 10; t++){
        int num;
        char key;
        ans = "";
        cin >> N;
        for(int i = 0; i < N; i++){
            int child[2] = {-1, -1};
            cin >> num;
            cin >> key;

            if(cin.get() != '\n'){
                cin >> child[0];
                if(cin.get() != '\n') cin >> child[1];
            }
            node[num].key = key;
            node[num].child[0] = child[0];
            node[num].child[1] = child[1];
        }
        inorder(1);
        cout << "#" << t << ' ';
        for(char ch : ans){
            cout << ch;
        }
        cout << '\n';
	}
	return 0;
}