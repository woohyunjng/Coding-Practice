#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 400000;

int L[MAX], R[MAX], ans[MAX], in[MAX], out[MAX];
vector<int> arr[MAX], adj[MAX], rev[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, cnt = 0;
    queue<int> q;
    bool ans_b = true;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i];

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), in[Y]++;
        rev[Y].push_back(X), out[X]++;
    }

    for (int i = 1; i <= N; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty()) {
        X = q.front(), q.pop(), cnt++;
        for (int i : adj[X]) {
            L[i] = max(L[i], L[X] + 1);
            if (!--in[i])
                q.push(i);
        }
    }
    if (cnt != N)
        ans_b = false;

    for (int i = 1; i <= N; i++)
        if (!out[i])
            q.push(i);
    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : rev[X]) {
            R[i] = min(R[i], R[X] - 1);
            if (!--out[i])
                q.push(i);
        }
    }

    for (int i = 1; i <= N; i++)
        arr[L[i]].push_back(i);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr V;

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i])
            pq.push({R[j], j});
        ans_b &= !pq.empty();
        if (!pq.empty()) {
            V = pq.top(), pq.pop();
            ans_b &= i <= V[0], ans[i] = V[1];
        }
    }

    if (ans_b) {
        for (int i = 1; i <= N; i++)
            cout << ans[i] << '\n';
    } else
        cout << -1 << '\n';
}
