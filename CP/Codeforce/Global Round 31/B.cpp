#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

string A[MAX];

string calc(string X, string Y) {
    string XF = X + Y, YF = Y + X;
    return XF < YF ? XF : YF;
}

void solve() {
    int N;

    string S = "";

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], S = calc(S, A[i]);
    cout << S << '\n';
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