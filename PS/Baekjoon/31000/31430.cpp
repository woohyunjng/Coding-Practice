#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, A, B;
    string S;

    cin >> T;
    if (T == 1) {
        cin >> A >> B, A += B, S = "";
        for (int i = 0; i < 13; i++)
            S += 'a' + (A % 26), A /= 26;
        cout << S << '\n';
    } else {
        cin >> S, A = 0;
        for (int i = 12; i >= 0; i--)
            A = A * 26 + (S[i] - 'a');
        cout << A << '\n';
    }

    return 0;
}