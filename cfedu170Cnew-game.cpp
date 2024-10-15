#include <vector>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t -- > 0) {
        int n, k;
        cin >> n >> k;
        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }
        int MAX = 1e9;
        sort(cards.begin(), cards.end());
        //two-pointers
        //for each cards[left pointer], try to move right pointer as far as possible. check for consecutive with previous right pointer, and check for k
        int max_length = 1;
        int p2 = 0;
        for (int p1 = 0; p1 < n; p1++) {
            p2 = max(p1, p2);
            while (p2 + 1 < n && cards[p2+1]<=cards[p2]+1 && cards[p2 + 1] < cards[p1] + k) {
                p2++;
                max_length = max(max_length, p2 - p1 + 1);
            }
            max_length = max(max_length, p2 - p1 + 1);
        }
        cout << max_length << endl;
    }
}