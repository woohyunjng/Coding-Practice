#include <bits/stdc++.h>
#define int long long

#define MAX 1500000
using namespace std;

typedef array<int, 2> pr;

int S[MAX], T[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    pr X;
    string s, t;

    priority_queue<pr> pq;

    cin >> N >> M >> s >> t;
    for (int i = 1; i <= N; i++)
        S[i] = s[i - 1] - '0';
    for (int i = 1; i <= M; i++)
        T[i] = t[i - 1] - '0';

    for (int i = 1; i <= M; i++)
        pq.push({T[i], i});

    K = 1;
    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        while (S[K] >= X[0])
            K++;
        if (K <= N)
            S[K++] = X[0], chk[X[1]] = true;
    }

    if (!chk[M]) {
        K = 0;
        for (int i = 1; i <= N; i++)
            if (S[i] <= T[M]) {
                S[i] = T[M], K = 1;
                break;
            }
        if (!K)
            S[N] = T[M];
    }

    for (int i = 1; i <= N; i++)
        cout << S[i];
    cout << '\n';

    return 0;
}