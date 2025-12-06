#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int S[MAX], T[MAX], C[2][26];

void solve() {
    string _S, _T, ans = "";
    int N, M, X = 1;

    fill(C[0], C[0] + 26, 0), fill(C[1], C[1] + 26, 0);

    cin >> _S >> _T, N = _S.size(), M = _T.size();
    for (int i = 1; i <= N; i++)
        S[i] = _S[i - 1] - 'a', C[0][S[i]]++;
    for (int i = 1; i <= M; i++)
        T[i] = _T[i - 1] - 'a', C[1][T[i]]++;

    bool flag = true;
    for (int i = 0; i < 26; i++)
        flag &= C[0][i] <= C[1][i], C[1][i] -= C[0][i];

    if (!flag) {
        cout << "Impossible" << '\n';
        return;
    }

    for (int i = 0; i < 26; i++) {
        while (X <= N && S[X] <= i)
            ans += 'a' + S[X++];
        while (C[1][i]--)
            ans += 'a' + i;
    }

    for (; X <= N; X++)
        ans += 'a' + S[X];

    cout << ans << '\n';
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