#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1'000'001;

int P[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, K, ans = 0, X = 0, C = 1, V, D;

    cin >> N >> L >> K;
    for (int i = 1; i <= K; i++)
        cin >> P[i], S[P[i] - 1]++;
    for (int i = 1; i < L; i++)
        S[i] += S[i - 1];

    while (N > 0) {
        ans++, D = (X + C) / L;
        V = -(X == 0 ? 0 : S[X - 1]) + S[L - 1] * D + ((X + C) % L == 0 ? 0 : S[(X + C - 1) % L]);
        X = (X + C) % L, C += V, N -= D;
    }

    cout << ans << '\n';
}