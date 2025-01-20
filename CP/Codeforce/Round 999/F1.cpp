#include <bits/stdc++.h>
#define int long long

#define MAX 500000
using namespace std;

void solve() {
    int N, res = 0, K, X, Y, Z, W;
    bool chk = true;

    string s, t;

    vector<int> S, T;

    cin >> s >> t;
    N = s.size(), X = 0, Y = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == '1')
            X++;
        if (t[i] == '1')
            Y++;
    }
    chk = X == Y;

    K = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && s[i] != s[i - 1])
            S.push_back(K * (s[i - 1] == '0' ? 1 : -1)), K = 0;
        K++;
    }
    S.push_back(K * (s[N - 1] == '0' ? 1 : -1));

    K = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && t[i] != t[i - 1])
            T.push_back(K * (t[i - 1] == '0' ? 1 : -1)), K = 0;
        K++;
    }
    T.push_back(K * (t[N - 1] == '0' ? 1 : -1));

    if (S.back() * T.back() < 0) {
        if (S.size() >= 3) {
            X = S.back(), S.pop_back();
            Y = S.back(), S.pop_back();
            S[S.size() - 1] += X, S.push_back(Y);
        } else if (S.size() == 2) {
            X = S.back(), S.pop_back();
            Y = S.back(), S.pop_back();
            S.push_back(X), S.push_back(Y);
        } else
            chk = false;
        res++;
    }

    for (int i = 0; i < S.size(); i++)
        S[i] = abs(S[i]);
    for (int i = 0; i < T.size(); i++)
        T[i] = abs(T[i]);

    while (chk && S.size() > T.size()) {
        if (S.back() >= T.back()) {
            chk &= S.back() == T.back();
            S.pop_back(), T.pop_back();
            continue;
        }

        if (S.size() >= 4) {
            X = S.back(), S.pop_back();
            Y = S.back(), S.pop_back();
            Z = S.back(), S.pop_back();
            W = S.back(), S.pop_back();
            S.push_back(Y + W), S.push_back(X + Z);
        } else if (S.size() == 3) {
            X = S.back(), S.pop_back();
            Y = S.back(), S.pop_back();
            Z = S.back(), S.pop_back();
            S.push_back(Y), S.push_back(X + Z);
        } else
            chk = false;
        res++;
    }

    for (int i = 0; i < S.size(); i++)
        chk &= S[i] == T[i];

    cout << (chk ? res : -1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}