#include<iostream>
#include<string>
using namespace std;
struct Node{
    string key;
    int child[2];
};
int T, N;
Node node[1001];
int ans;

int postorder(int num){
    int a, b;
    if(node[num].child[0] != -1)
        a = postorder(node[num].child[0]);
    if(node[num].child[1] != -1)
        b = postorder(node[num].child[1]);
    string str = node[num].key;

    if(str[0] == '+') return a + b;
    if(str[0] == '-') return a - b;
    if(str[0] == '*') return a * b;
    if(str[0] == '/') return a / b;
    return stoi(str);
}

int main(int argc, char** argv){
	for(int t = 1; t <= 10; t++){
        int num;
        string key;

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
        ans = postorder(1);
        cout << "#" << t << ' ' << ans << '\n';
	}
	return 0;
}