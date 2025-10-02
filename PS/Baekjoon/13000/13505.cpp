#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

struct Node {
    int child[2] = {-1, -1};
    Node() {};
};

vector<Node> trie;
int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0, V;

    cin >> N, trie.push_back(Node());

    for (int i = 0; i < N; i++) {
        cin >> A[i], X = 0;
        for (int j = 30; j >= 0; j--) {
            Y = (A[i] >> j) & 1;
            if (trie[X].child[Y] == -1)
                trie[X].child[Y] = trie.size(), trie.push_back(Node());
            X = trie[X].child[Y];
        }
    }

    for (int i = 0; i < N; i++) {
        X = 0, V = 0;
        for (int j = 30; j >= 0; j--) {
            Y = (A[i] >> j) & 1;
            if (trie[X].child[!Y] != -1)
                Y ^= 1;
            V ^= Y ? (1 << j) : 0, X = trie[X].child[Y];
        }
        ans = max(ans, V ^ A[i]);
    }

    cout << ans << '\n';

    return 0;
}