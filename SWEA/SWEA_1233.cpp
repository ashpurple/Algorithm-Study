#include<iostream>
using namespace std;
struct Node{
    string key;
    int child[2];
};
int T, N;
Node node[201];
string oper[4] = {"+", "-", "/", "*"};
bool flag;
int cnt;

bool isOper(string ch){
    for(int i = 0; i < 4; i++){
        if(ch == oper[i]) return true;
    }
    return false;
}

void inorder(int num){
    if(node[num].child[0] != -1)
        inorder(node[num].child[0]);
    if(isOper(node[num].key)) cnt--;
    else cnt++;
    if(cnt > 1 || cnt < 0) flag = false;
    if(node[num].child[1] != -1)
        inorder(node[num].child[1]);
}

int main(int argc, char** argv){
	for(int t = 1; t <= 10; t++){
        int num;
        string key;
        cnt = 0;
        flag = true;
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
        if(flag) cout << "#" << t << ' ' << 1 << '\n';
        else cout << "#" << t << ' ' << 0 << '\n';

	}
	return 0;
}