#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;
const int INF = 0x1f1f1f1f1f1f1f1f;

int S[MAX], L[MAX], R[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, C, X, ans = 0;

    cin >> N >> M >> K, C = (M + K) / 2;

    for (int i = 1; i <= M; i++)
        cin >> X, chk[X] = true;

    for (int i = 1; i <= N; i++)
        S[i] = S[i - 1] + chk[i];

    queue<int> q;

    X = 0;
    for (int i = 1; i <= C; i++) {
        if (!chk[i])
            X += S[i] + (int)q.size(), q.push(S[i]);
        L[i] = -INF;
    }
    L[C] = X;

    for (int i = C + 1; i <= N && S[i] < C; i++) {
        X -= q.front() + q.size() - 1, q.pop();
        if (!chk[i])
            X += S[i] + (int)q.size(), q.push(S[i]);
        L[i] = X;
    }

    while (!q.empty())
        q.pop();

    X = 0;
    for (int i = N; i >= N - C + 1; i--) {
        if (!chk[i])
            X += S[N] - S[i - 1] + (int)q.size(), q.push(S[N] - S[i - 1]);
        R[i] = -INF;
    }
    R[N - C + 1] = X;

    for (int i = N - C; i >= 1 && S[N] - S[i - 1] < C; i--) {
        X -= q.front() + q.size() - 1, q.pop();
        if (!chk[i])
            X += S[N] - S[i - 1] + (int)q.size(), q.push(S[N] - S[i - 1]);
        R[i] = X;
    }

    for (int i = 1; i <= N; i++) {
        if (S[i] > C)
            L[i] = -INF;
        if (S[N] - S[i - 1] > C)
            R[i] = -INF;
    }

    for (int i = 1; i <= N; i++) {
        if ((M + K) & 1) {
            if (chk[i])
                ans = max(ans, L[i - 1] + R[i + 1]);
            else
                ans = max(ans, L[i - 1] + R[i + 1] + C);
        } else
            ans = max(ans, L[i] + R[i + 1]);
    }

    ans = (2 * M + K - 1) * K / 2 - ans * 2;
    cout << ans << '\n';

    return 0;
}