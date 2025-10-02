#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V = 1, ans = 1;
    string S;

    cin >> S, N = S.size();
    for (int i = 1; i < N; i++) {
        V = S[i - 1] < S[i] ? V + 1 : 1;
        ans += V;
    }

    cout << ans << '\n';

    return 0;
}