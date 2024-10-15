#include <vector>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main() {
    int q;
    cin >> q;
    while (q -- > 0) {
        string s, t;
        cin >> s;
        cin >> t;
        int index = 0;
        while (index < s.size() && index < t.size() &&
        s[index] == t[index]) {
            index++;
        }
        int ans = 0;
        ans += s.size() - index;
        ans += t.size() - index;
        ans += index;
        if (index != 0) {
            ans++;
        }
        cout << ans << endl;
    }
}