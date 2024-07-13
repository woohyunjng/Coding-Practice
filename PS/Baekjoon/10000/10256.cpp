#include <bits/stdc++.h>
using namespace std;

struct Node {
    int children[26];
    int pi = 0;
    bool output = false;
    Node() { fill(children, children + 26, -1); }
};

class AhoCorasick {
  public:
    vector<Node> trie;
    AhoCorasick() { trie.push_back(Node()); }

    void insert(string &S) {
        int cur = 0, c;

        for (char ch : S) {
            c = ch - 'A';
            if (trie[cur].children[c] == -1) {
                trie[cur].children[c] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].children[c];
        }
        trie[cur].output = true;
    }

    void build() {
        queue<int> q;
        int c, p, cur, child;

        for (c = 0; c < 26; c++) {
            child = trie[0].children[c];
            if (child == -1)
                trie[0].children[c] = 0;
            else {
                trie[child].pi = 0;
                q.push(child);
            }
        }

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            for (c = 0; c < 26; c++) {
                child = trie[cur].children[c];
                if (child == -1)
                    continue;

                p = trie[cur].pi;
                while (trie[p].children[c] == -1)
                    p = trie[p].pi;

                p = trie[p].children[c];
                trie[child].pi = p;
                if (trie[p].output)
                    trie[child].output = true;

                q.push(child);
            }
        }
    }

    int query(string &S) {
        int cur = 0, c, res = 0;

        for (char ch : S) {
            c = ch - 'A';
            while (trie[cur].children[c] == -1)
                cur = trie[cur].pi;
            cur = trie[cur].children[c];
            if (trie[cur].output)
                res++;
        }

        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, M;
    string S, P;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        cin >> S;
        cin >> P;

        AhoCorasick ac;

        for (int i = 1; i <= M; i++) {
            for (int j = 0; j <= M - i; j++) {
                reverse(P.begin() + j, P.begin() + j + i);
                ac.insert(P);
                reverse(P.begin() + j, P.begin() + j + i);
            }
        }
        ac.build();
        cout << ac.query(S) << '\n';
    }

    return 0;
}