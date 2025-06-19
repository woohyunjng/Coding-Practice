#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 200001;

struct Node {
    int ch[2], bit, t;
    vector<int> arr;

    Node(int b, int t) : ch{0, 0}, bit(b), t(t) {}
};

int A[MAX], ans;
vector<Node> trie;

int query(int C, int K) {
    int res = ((1ll << trie[C].bit) & K) ^ (trie[C].t << trie[C].bit);
    if (trie[C].bit == 0)
        return res;
    if (K & (1ll << (trie[C].bit - 1)))
        res += query(trie[C].ch[1] ? trie[C].ch[1] : trie[C].ch[0], K);
    else
        res += query(trie[C].ch[0] ? trie[C].ch[0] : trie[C].ch[1], K);
    return res;
}

void dnc(int C) {
    int V = 0;
    if (trie[C].ch[0] > 0 && trie[C].ch[1] > 0) {
        V = 2147483647;
        for (int i : trie[trie[C].ch[0]].arr)
            V = min(V, query(trie[C].ch[1], A[i]));
        ans += V;
    }

    if (trie[C].ch[0] > 0)
        dnc(trie[C].ch[0]);
    if (trie[C].ch[1] > 0)
        dnc(trie[C].ch[1]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, K;
    vector<int> arr;

    trie.push_back(Node(31, 0));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], C = 0;
        for (int j = 30; j >= 0; j--) {
            K = (A[i] & (1ll << j)) >> j;
            if (trie[C].ch[K] == 0) {
                trie[C].ch[K] = trie.size();
                trie.push_back(Node(j, K));
            }
            C = trie[C].ch[K], trie[C].arr.push_back(i);
        }
    }

    dnc(0);
    cout << ans << '\n';

    return 0;
}