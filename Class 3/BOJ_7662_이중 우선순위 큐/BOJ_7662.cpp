#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<int> num;
    int T, k, n;
    char cmd;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> cmd >> n;
            if (cmd == 'I')
                num.insert(n);
            else if (!num.empty()) {
                if (n == 1)
                    num.erase(--num.end());
                else
                    num.erase(num.begin());
            }
        }
        if (num.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *(--num.end()) << ' ' << *num.begin() << '\n';
        num.clear();
    }
}