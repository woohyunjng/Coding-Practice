#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

struct Node {
    int child[2] = {-1, -1}, S = 0;
    Node() {}
};

vector<Node> trie;

int dfs(int node, int cnt) {
    if (node == -1 || trie[node].S == cnt)
        return 0;
    else if (trie[node].child[0] == -1 && trie[node].child[1] == -1)
        return trie[node].S - cnt;

    int l = trie[node].child[0], r = trie[node].child[1];
    if (l == -1)
        return dfs(r, cnt + 1) + 1;
    else if (r == -1)
        return dfs(l, cnt + 1) + 1;
    else
        return max(dfs(l, max(0ll, cnt - trie[r].S) + 1), dfs(r, max(0ll, cnt - trie[l].S) + 1)) + 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, K, Y, ans;

    cin >> N, trie.push_back(Node());
    for (int i = 0; i < N; i++) {
        cin >> X, K = 0, trie[K].S++;
        for (int j = 0; j < 60; j++) {
            Y = X >> j & 1;
            if (trie[K].child[Y] == -1)
                trie[K].child[Y] = trie.size(), trie.push_back(Node());
            K = trie[K].child[Y], trie[K].S++;
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}