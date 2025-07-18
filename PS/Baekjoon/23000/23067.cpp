#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX], L[MAX], R[MAX], G[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, Y, ans = 0, S = 0;
    priority_queue<int> pq;

    cin >> N, X = -N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], L[i] = X;
        if (A[i] == -1)
            X = i;
        ans += max(0ll, A[i]);
    }

    X = N * 2, Y = N * 2;
    for (int i = N; i >= 1; i--) {
        R[i] = X, G[i] = Y;
        if (A[i] == -1)
            X = i;
        if (A[i] != 0)
            Y = i;
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] <= 0)
            continue;
        X = min(R[i] - i, i - L[i]) * 2;
        for (int j = 1; j < A[i]; j++) {
            if (S < i)
                ans--, S += X, pq.push(X);
            else if (X < pq.top())
                S -= pq.top(), pq.pop(), pq.push(X), S += X;
            else
                break;
        }
        X = min(R[i] - G[i], i - L[i]) * 2;
        if (S < i)
            ans--, S += X, pq.push(X);
        else if (X < pq.top())
            S -= pq.top(), pq.pop(), pq.push(X), S += X;
    }

    cout << ans << '\n';

    return 0;
}