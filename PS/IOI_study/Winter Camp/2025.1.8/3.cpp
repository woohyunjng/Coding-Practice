#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node {
    int children[26];
    int pi = 0;
    bool output = false;
    Node() { fill(children, children + 26, -1); }
};

vector<Node> trie;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    trie.push_back(Node());

    int N, Q, cur, child, c, p;
    bool res;
    string S;
    queue<int> q;

    cin >> N;
    while (N--) {
        cin >> S, cur = 0;
        for (char ch : S) {
            c = ch - 'a';
            if (trie[cur].children[c] == -1) {
                trie[cur].children[c] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].children[c];
        }
        trie[cur].output = true;
    }

    for (c = 0; c < 26; c++) {
        child = trie[0].children[c];
        if (child == -1)
            trie[0].children[c] = 0;
        else
            trie[child].pi = 0, q.push(child);
    }

    while (!q.empty()) {
        cur = q.front(), q.pop();

        for (c = 0; c < 26; c++) {
            child = trie[cur].children[c];
            if (child == -1)
                continue;

            p = trie[cur].pi;
            while (trie[p].children[c] == -1)
                p = trie[p].pi;

            p = trie[p].children[c], trie[child].pi = p;
            if (trie[p].output)
                trie[child].output = true;
            q.push(child);
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> S, cur = 0, res = false;

        for (char ch : S) {
            c = ch - 'a';
            while (trie[cur].children[c] == -1)
                cur = trie[cur].pi;
            cur = trie[cur].children[c];
            res = res || trie[cur].output;
        }

        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}