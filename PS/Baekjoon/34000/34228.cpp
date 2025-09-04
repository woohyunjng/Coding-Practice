#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

struct Node {
    int child[2] = {-1, -1};
    Node() {};
};

int A[MAX], B[MAX];
vector<Node> trie;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T = 0, ans = 0, X, Y, V;

    trie.push_back(Node());

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], T ^= A[i];
    for (int i = 1; i <= N; i++) {
        cin >> B[i], T ^= B[i], X = 0;
        for (int j = 30; j >= 0; j--) {
            Y = (B[i] & (1 << j)) >> j;
            if (trie[X].child[Y] == -1)
                trie[X].child[Y] = trie.size(), trie.push_back(Node());
            X = trie[X].child[Y];
        }
    }

    for (int i = 1; i <= N; i++) {
        X = 0, V = T ^ A[i];
        for (int j = 30; j >= 0; j--) {
            Y = (V & (1 << j)) >> j;
            if (trie[X].child[Y] == -1)
                Y ^= 1;
            X = trie[X].child[Y], V ^= Y ? (1 << j) : 0;
        }
        ans = max(ans, V);
    }

    cout << ans << '\n';

    return 0;
}