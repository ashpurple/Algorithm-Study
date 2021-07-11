#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
	deque<int> deq;
	string cmd;
	cin >> num;
 
	for (int i = 0; i < num; i++) {
		string cmd;
        cin >> cmd;
        if (cmd == "front") {
            if (deq.empty()) 
                cout << -1 << "\n";
            else 
                cout << deq.front() << "\n";
        }
        else if (cmd == "back") {
            if (deq.empty()) 
                cout << -1 << "\n";
            else 
                cout << deq.back() << "\n";
        }
        else if (cmd == "push_front") {
            int x;
            cin >> x;
            deq.push_front(x);
        }
        else if(cmd == "push_back"){
            int x;
            cin >> x;
            deq.push_back(x);
        }
        else if (cmd == "pop_front") {
            if (deq.empty()) 
                cout << -1 << "\n";
            else{
                cout << deq.front() << "\n";
                deq.pop_front();
                }
            }
        else if(cmd == "pop_back"){
            if (deq.empty()) 
                cout << -1 << "\n";
            else{
                cout << deq.back() << "\n";
                deq.pop_back();
            }
            
        }
        else if (cmd == "size")
            cout << deq.size() << "\n";
        else if (cmd == "empty") {
            if (deq.empty()) 
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
}
