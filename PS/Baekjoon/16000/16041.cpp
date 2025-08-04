#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int in[MAX];
bool chk[MAX];
vector<int> adj[MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, X, S = 0, ans = 0;
    bool flag = true;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
        in[U]++, in[V]++;
    }

    for (int i = 1; i <= N; i++)
        arr[in[i]].push_back(i);

    for (int i = N; i >= 0 && flag; i--) {
        X = i + 1;
        for (int j : arr[i]) {
            V = 0;
            for (int k : adj[j])
                V += chk[k];
            flag &= V == S, S++, chk[j] = true;
        }
    }

    flag = false, S = 0;
    for (int i = 1; i <= N; i++) {
        S += in[i] >= X;
        for (int j : adj[i])
            flag |= in[i] < X && in[j] < X;
    }
    if (flag) {
        cout << 0 << '\n';
        return 0;
    }

    ans = 1;
    for (int i = 1; i <= N; i++) {
        if (in[i] >= X)
            ans += in[i] == S - 1;
        else {
            V = 0;
            for (int j : adj[i])
                V += in[j] >= X;
            ans += V == S;
        }
    }

    cout << ans << '\n';

    return 0;
}