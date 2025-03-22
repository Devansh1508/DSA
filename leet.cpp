#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> P, max_power;

int dfs(int node, int parent) {
    int max_child_power = 0;
    for (int child : tree[node]) {
        if (child == parent) continue;
        max_child_power = max(max_child_power, dfs(child, node));
    }
    return max_power[node] = P[node] + max(0, max_child_power);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    P.resize(N + 1);
    tree.resize(N + 1);
    max_power.resize(N + 1, 0);
    
    for (int i = 1; i <= N; i++) cin >> P[i];

    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    cout << dfs(1, -1) << '\n';
}
