#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0, S = 0;

    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S += A[i];

    for (int st = 0, en = N * 1000000, md; st <= en;) {
        md = st + en >> 1;
        if (S + md * 100 >= X * (N + md))
            ans = md, en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}