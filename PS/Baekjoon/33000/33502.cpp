#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int S[MAX], ans[MAX], uf[MAX], P[MAX];
vector<int> adj[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
int calc(int X) {
    X = find(X);
    return P[X] * (P[X] - 1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    string _S;

    cin >> N >> M >> _S;
    for (int i = 1; i <= N; i++)
        S[i] = _S[i - 1] == '1', uf[i] = i;

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
        if (S[X] && S[Y] && find(X) != find(Y)) {
            X = find(X), Y = find(Y), ans[N + 1] -= calc(X) + calc(Y);
            if (X > Y)
                swap(X, Y);
            uf[Y] = X, ans[N + 1] += calc(X);
        }
    }

    for (int i = N; i >= 1; i--) {
        ans[i] = ans[i + 1] - calc(i), P[find(i)]++, ans[i] += calc(i);
        for (int j : adj[i]) {
            if (!S[j] && j < i || find(i) == find(j))
                continue;
            X = find(i), Y = find(j);
            if (X > Y)
                swap(X, Y);
            ans[i] -= calc(X) + calc(Y), uf[Y] = X, P[X] += P[Y], ans[i] += calc(X);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}