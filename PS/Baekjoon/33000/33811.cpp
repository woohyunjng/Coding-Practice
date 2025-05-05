#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int N, X = 0, Y = 0, ans = 0;

    cin >> N >> S;

    for (int i = 0; i < N - 3; i++) {
        if (S[i] == 'S' && S[i + 1] == 'S' && S[i + 2] == 'H' && S[i + 3] == 'S')
            X++;
        else if (S[i] == 'G' && S[i + 1] == 'S' && S[i + 2] == 'H' && S[i + 3] == 'S')
            X--;
        ans = max(ans, X - Y), Y = min(X, Y);
    }

    cout << ans << '\n';

    return 0;
}