#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1500000;

int F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans;
    string S;

    cin >> N >> S, X = 0;

    for (int i = 1; i < N; i++) {
        while (X > 0 && S[i] != S[X])
            X = F[X - 1];
        if (S[i] == S[X])
            F[i] = ++X;
    }

    ans = N - F[N - 1];
    cout << ans << '\n';

    return 0;
}