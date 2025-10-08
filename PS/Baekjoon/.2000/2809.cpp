#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 300001;

struct Node {
    int depth = 0, pi = 0, val = 0;
    bool output = false;
    vector<pr> children;

    Node() {}
};

int findc(vector<pr> &v, int c) {
    int x = lower_bound(v.begin(), v.end(), pr{c, 0}) - v.begin();
    if (x == v.size() || v[x][0] != c)
        return -1;
    return v[x][1];
}

void push(vector<pr> &v, int c, int n) {
    v.insert(lower_bound(v.begin(), v.end(), pr{c, 0}), pr{c, n});
}

vector<Node> trie;
int V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, T;
    int N, M, X, C, P, ans = 0;

    cin >> N >> S;

    cin >> M, trie.push_back(Node());
    for (int i = 0; i < M; i++) {
        cin >> T, X = 0;
        for (char j : T) {
            C = j - 'a';
            if (findc(trie[X].children, C) == -1) {
                push(trie[X].children, C, (int)trie.size());
                trie.push_back(Node()), trie.back().depth = trie[X].depth + 1;
            }
            X = findc(trie[X].children, C);
        }
        trie[X].output = true, trie[X].val = max(trie[X].val, (int)T.size());
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        C = findc(trie[0].children, i);
        if (C == -1)
            push(trie[0].children, i, 0);
        else
            trie[C].pi = 0, q.push(C);
    }

    while (!q.empty()) {
        X = q.front(), q.pop();

        for (int i = 0; i < 26; i++) {
            C = findc(trie[X].children, i);
            if (C == -1)
                continue;

            P = trie[X].pi;
            while (findc(trie[P].children, i) == -1)
                P = trie[P].pi;

            P = findc(trie[P].children, i), trie[C].pi = P;
            if (trie[P].output)
                trie[C].output = true, trie[C].val = max(trie[C].val, trie[P].val);
            q.push(C);
        }
    }

    X = 0;
    for (int i = 0; i < N; i++) {
        C = S[i] - 'a';
        while (findc(trie[X].children, C) == -1)
            X = trie[X].pi;
        X = findc(trie[X].children, C);
        if (trie[X].output)
            V[i + 1]--, V[i - trie[X].val + 1]++;
    }

    ans = V[0] == 0;
    for (int i = 1; i < N; i++)
        V[i] += V[i - 1], ans += V[i] == 0;

    cout << ans << '\n';

    return 0;
}