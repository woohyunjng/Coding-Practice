#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int V[MAX], S[MAX], X[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, ans = 0;
    bool ans_chk = true;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> V[i], S[i] = S[i - 1] + V[i];
    cin >> T;

    for (int i = 1; i <= N; i++)
        X[i] = S[N] - S[i - 1] - S[i];

    for (int i = N - 1; i >= 1; i--)
        T -= (N - i) * V[i], ans += (N - i) * V[i] * X[i];

    M -= T / S[N] + N - 1;
    for (int i = 1; i <= N; i++)
        ans += (T / S[N]) * V[i] * X[i];
    ans_chk = T >= 0;

    T %= S[N], M -= T != 0;
    for (int i = 1; i <= N; i++)
        ans += min(V[i], T) * X[i], T -= min(V[i], T);

    ans_chk &= M >= 0 && T >= 0;
    if (!ans_chk)
        cout << "Sad" << '\n';
    else {
        cout << "Happy" << '\n';
        cout << ans << '\n';
    }

    return 0;
}