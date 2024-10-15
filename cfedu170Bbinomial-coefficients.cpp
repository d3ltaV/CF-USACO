#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
long long powerMod(int base, int exp, int mod) {
    long long result = 1;
    long long baseMod = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * baseMod) % mod;
        }
        exp /= 2;
        baseMod = (baseMod * baseMod) % mod;
    }
    return result;
}
int main() {
    int t;
    cin >> t; 
    vector<int> n(t);
    vector<int> k(t);
    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++) {
        cin >> k[i];
    }
    int MOD = 1e9 + 7;
    int MAX = 1e5;
    vector<int> ans;
    for (int i = 0; i < t; i++) {
        if (n[i] == k[i]) {
            ans.push_back(1);
        } else {
            ans.push_back(powerMod(2, k[i], MOD));
        }
    }
}
