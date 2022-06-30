#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> tree;
map<string, int> money;

void getMoney(string seller, int price){
    if(seller == "-") return;
    int tax = (price * 0.1);
    int intake = price - tax;
    money[seller] = money[seller] + intake;
    if(tax == 0) return;
    getMoney(tree[seller], tax);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++) {
        tree[enroll[i]] = referral[i];
    }
    for (int i = 0; i < seller.size(); i++) {
        getMoney(seller[i], amount[i] * 100);
    }
    for(int i = 0;i < enroll.size(); i++){
        answer.push_back(money[enroll[i]]);
    }
    
    return answer;
}