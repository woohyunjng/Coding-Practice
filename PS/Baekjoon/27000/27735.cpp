#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 500001;

typedef array<int, 3> tp;

vector<int> arr, sbt[MAX];
priority_queue<tp, vector<tp>, greater<tp>> tree[MAX];

int V[MAX], S[MAX], VR[MAX], CS[MAX][40];

void split(int x, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        sbt[x].push_back(n);
    else {
        int m = s + e >> 1;
        split(x, n << 1, s, m, l, r), split(x, n << 1 | 1, m + 1, e, l, r);
    }
}

void cont(int n, int s, int e, int x) {
    arr.push_back(n);
    if (s ^ e) {
        int m = s + e >> 1;
        if (x <= m)
            cont(n << 1, s, m, x);
        else
            cont(n << 1 | 1, m + 1, e, x);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, L, R, K, I, C, P = 0, ans = 0;
    tp M;

    vector<int> val, upd;

    cin >> N >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            ++P, cin >> L >> R >> V[P], L ^= ans, R ^= ans;
            split(P, 1, 1, N, L, R), C = sbt[P].size();
            K = (V[P] + C - 1) / C;
            for (int i = 0; i < C; i++)
                tree[sbt[P][i]].push({S[sbt[P][i]] + K, P, 0}), CS[P][i] = S[sbt[P][i]];
        } else {
            cin >> I >> C, I ^= ans, cont(1, 1, N, I);

            for (int i : arr) {
                S[i] += C;
                while (!tree[i].empty() && tree[i].top()[0] <= S[i]) {
                    M = tree[i].top(), tree[i].pop();
                    if (VR[M[1]] != M[2])
                        continue;
                    upd.push_back(M[1]);
                }
            }

            for (int i : upd) {
                VR[i]++;
                for (int j = 0; j < sbt[i].size(); j++)
                    V[i] -= S[sbt[i][j]] - CS[i][j], CS[i][j] = S[sbt[i][j]];
                if (V[i] <= 0) {
                    val.push_back(i);
                    continue;
                }
                C = sbt[i].size(), K = (V[i] + C - 1) / C;
                for (int j : sbt[i])
                    tree[j].push({S[j] + K, i, VR[i]});
            }
            upd.clear();

            sort(val.begin(), val.end()), cout << val.size() << ' ';
            for (int i : val)
                cout << i << ' ';
            cout << '\n', ans = val.size();
            arr.clear(), val.clear();
        }
    }

    return 0;
}