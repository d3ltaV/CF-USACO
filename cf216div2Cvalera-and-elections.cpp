
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void dfs(int node, int p, const vector<vector<pair<int, int>>>& adj,  vector<pair<int, int>>& path,  vector<vector<pair<int, int>>>& ancestors) {
    if (p != -1) {
        for (auto& child : adj[p]) {
            if (child.first == node) {
                path.push_back({node, child.second});
                break;
            }
        }
    } else {
        path.push_back({node, -1});
    }
    if (node != 0 && adj[node].size() == 1) {
        ancestors[node] = path;
    } else {
        for (pair<int, int> child : adj[node]) {
            if (child.first != p) {
                dfs(child.first, node, adj, path, ancestors);
            }
        }
    }
    path.pop_back();
}
int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back(make_pair(b - 1, c));
        adj[b - 1].push_back(make_pair(a - 1, c));
    }
    vector<int> leaves;
    for (int i = 1; i < n; i++) { //skip node 1
        if (adj[i].size() == 1) {
            leaves.push_back(i);
        }
    }
    vector<vector<pair<int, int>>> ancestors(n);
    vector<pair<int, int>> path;
    vector<int> ans;
    dfs(0, -1, adj, path, ancestors);
    for (int i = 0; i < leaves.size(); i++) {
        for (int j = 0; j < ancestors[i].size(); j++) {
            if (ancestors[i][j].second == 2) {
                ans.push_back(i + 1);
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}