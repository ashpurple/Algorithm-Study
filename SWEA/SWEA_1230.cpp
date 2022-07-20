#include<iostream>
#include<vector>
using namespace std;
string ans;
vector <int> v;

int main(int argc, char** argv){
	int T, t, N, M;

	for(t = 1; t <= 10; t++){
        vector <int> newV;
        v.swap(newV);
        cin >> N;

        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }

        char oper;
        int x, y, s;
        cin >> M;
        for(int i = 0; i < M; i++){
            cin >> oper;
            if(oper == 'I'){
                cin >> x >> y;
                for(int j = 0; j < y; j++){
                    cin >> s;
                    v.insert(v.begin() + x + j, s);
                }
            }
            else if(oper == 'D'){
                cin >> x >> y;
                for(int j = 0; j < y; j++){
                    v.erase(v.begin() + x);
                }
            }
            else if(oper == 'A'){
                cin >> y;
                for(int j = 0; j < y; j++){
                    cin >> s;
                    v.push_back(s);
                }
            }
            
        }
        cout << "#" << t;
        for(int i = 0; i < 10; i++) cout << ' ' << v[i];
        cout << '\n';
	}
	return 0;
}