#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C, D;
    bool ans = true;
    string S;

    cin >> N >> S, ans &= N % 2 == 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'P')
            A = i;
        else if (S[i] == 'A')
            B = i;
        else if (S[i] == 'U')
            C = i;
        else if (S[i] == 'L')
            D = i;
    }

    ans &= A < B && B < C && C < D;
    ans &= A % 2 == 0 && (B - A) % 2 == 1 && (C - B) % 2 == 1 && (D - C) % 2 == 1 && (N - 1 - D) % 2 == 0;

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}