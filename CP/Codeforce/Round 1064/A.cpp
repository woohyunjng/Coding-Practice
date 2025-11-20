#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX], uf[MAX], nxt[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    uf[Y] = X, nxt[X] = nxt[Y], A[X] = max(A[X], A[Y]);
}

void solve() {
    int N, X, ans = 0;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], uf[i] = i, nxt[i] = (i + 1) % N;
    for (int i = 0; i < N; i++)
        pq.push({max(A[i], A[nxt[i]]), i});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (find(K[1]) != K[1])
            continue;
        if (nxt[K[1]] == K[1])
            break;
        ans += K[0], uni(K[1], nxt[K[1]]), X = find(K[1]);
        pq.push({max(A[X], A[nxt[X]]), X});
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}