#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, X = 1, V;
    string S, ans = "";

    cin >> N >> T >> S, ans = S[0];
    for (X = 1; X < N; X++) {
        if (S[X] == S[X - 1]) {
            ans += S[X];
            continue;
        }
        V = X;
        while (X + 1 < N && S[X + 1] != S[X])
            X++;
        if (V == X) {
            ans += S[X];
            continue;
        }
        if (X + 1 == N || S[X + 1] == S[X])
            X--;
        for (int i = V; i <= min((X + V) / 2, V + T - 1); i++)
            ans += S[V - 1];
        for (int i = min((X + V) / 2, V + T - 1) + 1; i < max((X + V) / 2 + 1, X - T + 1); i++)
            ans += 'A' + ((S[i] - 'A') ^ (T & 1));
        for (int i = max((X + V) / 2 + 1, X - T + 1); i <= X; i++)
            ans += S[X + 1];
    }

    cout << ans << '\n';

    return 0;
}