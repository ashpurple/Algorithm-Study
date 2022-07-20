#include<iostream>
#include<vector>
using namespace std;
vector <int> v;

int main(int argc, char** argv){
	int T, N, M, L;
    cin >> T;
	for(int t = 1; t <= T; t++){
        vector <int> newV;
        v.swap(newV);
        cin >> N >> M >> L;

        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }

        char oper;
        int x, y;

        for(int i = 0; i < M; i++){
            cin >> oper;
            if(oper == 'I'){
                cin >> x >> y;
                v.insert(v.begin() + x, y);
            }
            else if(oper == 'D'){
                cin >> x;
                v.erase(v.begin() + x);
            }
            else if(oper == 'C'){
                cin >> x >> y;
                v[x] = y;
            }
            
        }
        if(v.size() < L + 1) cout << "#" << t << ' ' << -1 << '\n';
        else cout << "#" << t << ' ' << v[L] << '\n';
	}
	return 0;
}