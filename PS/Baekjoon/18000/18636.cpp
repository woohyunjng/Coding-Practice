#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], B[MAX], ans[MAX], in[MAX], inc[MAX], decr[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V = 0, X;
    queue<int> q;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1; i <= N; i++) {
        if (A[i] > 1)
            adj[inc[A[i] - 1]].push_back(i), in[i]++;
        if (inc[A[i]] != 0)
            adj[i].push_back(inc[A[i]]), in[inc[A[i]]]++;
        inc[A[i]] = i;
    }

    for (int i = N; i >= 1; i--) {
        if (B[i] > 1)
            adj[decr[B[i] - 1]].push_back(i), in[i]++;
        if (decr[B[i]] != 0)
            adj[i].push_back(decr[B[i]]), in[decr[B[i]]]++;
        decr[B[i]] = i;
    }

    for (int i = 1; i <= N; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        X = q.front(), q.pop(), ans[X] = ++V;
        for (int i : adj[X])
            if (--in[i] == 0)
                q.push(i);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}