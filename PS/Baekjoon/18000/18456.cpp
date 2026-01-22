#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 1e15;

int A[MAX], D[MAX], E[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, V = 0, C, S, VK[2] = {0, 0};

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cout << "Yes" << '\n';

    for (int st = 0, en = INF, md; st <= en;) {
        md = st + en >> 1, C = S = 0;
        for (int i = 1; i <= N; i++) {
            S += A[i];
            if (S >= md)
                S = 0, C++;
        }
        if (C >= K)
            st = md + 1, V = md;
        else
            en = md - 1;
    }

    S = 0;
    for (int i = 1; i <= N; i++) {
        S += A[i];
        if (S >= V)
            S = 0, D[++VK[0]] = i;
    }
    if (VK[0] == K && D[VK[0]] == N) {
        for (int i = 1; i < VK[0]; i++)
            cout << D[i] << ' ';
        cout << '\n';
        return 0;
    }

    S = 0;
    for (int i = N; i >= 1; i--) {
        S += A[i];
        if (S >= V + 1)
            S = 0, E[++VK[1]] = i;
    }

    for (int i = max(1ll, K - VK[1]); i < K; i++) {
        assert(K - i >= 1 && K - i <= VK[1]);
        if (E[K - i] != D[i] + 1)
            continue;
        for (int j = 1; j <= i; j++)
            cout << D[j] << ' ';
        for (int j = K - i - 1; j >= 1; j--)
            cout << E[j] - 1 << ' ';
        cout << '\n';
        return 0;
    }

    for (int i = 1; i < K; i++)
        cout << i << ' ';
    cout << '\n';

    return 0;
}