#include<iostream>
using namespace std;
const int MOD = 1000000007;

long long bigNumMod(string num){
    long long res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (num[i] - '0')) % MOD;
    return res;
}