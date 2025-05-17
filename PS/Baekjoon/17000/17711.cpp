#include <bits/stdc++.h>
using namespace std;

const int MAX = 400001;
const int BUCKET = 700;

int N, X[MAX];
priority_queue<int> pq[BUCKET], inp[BUCKET];

void pq_update(int x) {
    while (!pq[x].empty())
        pq[x].pop();
    for (int i = x * BUCKET; i < min((x + 1) * BUCKET, N); i++)
        pq[x].push(X[i]);
}

void update(int x) {
    for (int i = x * BUCKET; i < min((x + 1) * BUCKET, N); i++)
        inp[x].push(-X[i]), X[i] = -inp[x].top(), inp[x].pop();
    while (!inp[x].empty())
        inp[x].pop();
}

int swp(int l, int r, int x) {
    for (int i = l; i <= r; i++)
        if (X[i] > x)
            swap(X[i], x);
    return x;
}

int query(int l, int r, int x) {
    if (l / BUCKET == r / BUCKET)
        update(l / BUCKET), x = swp(l, r, x), pq_update(l / BUCKET);
    else {
        update(l / BUCKET), x = swp(l, (l / BUCKET + 1) * BUCKET - 1, x), pq_update(l / BUCKET);
        for (int i = l / BUCKET + 1; i < r / BUCKET; i++)
            inp[i].push(-x), pq[i].push(x), x = pq[i].top(), pq[i].pop();
        update(r / BUCKET), x = swp(r / BUCKET * BUCKET, r, x), pq_update(r / BUCKET);
    }
    return x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, S, T, P;

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> X[i], pq[i / BUCKET].push(X[i]);

    while (Q--) {
        cin >> S >> T >> P, S--, T--;
        if (S <= T)
            P = query(S, T, P);
        else
            P = query(0, T, query(S, N - 1, P));
        cout << P << '\n';
    }

    return 0;
}