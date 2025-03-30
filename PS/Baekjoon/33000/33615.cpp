#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, X, Y, K = 0;
    string S;

    cin >> T;
    while (T--) {
        cin >> S, N = S.size(), K = 0;
        for (char i : S)
            K += i - '0';

        if (S[N - 1] == '5')
            X = 0, Y = 5;
        else if (K % 3 == 0)
            X = 0, Y = 3;
        else if (S.find('5') == string::npos)
            X = N % 2, Y = 11;
        else if (K % 3 == 1)
            X = S.find('1') + 1, Y = 3;
        else
            X = S.find('5') + 1, Y = 3;

        cout << X << ' ' << Y << '\n';
    }

    return 0;
}