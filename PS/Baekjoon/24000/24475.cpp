#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef __int128_t ll;

const int MAX = 400000;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, st, en, md, ans;
    ll X, Y;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i], A[i] = max(A[i], B[i]);

    st = 0, en = 1000000000000000000, ans = 0;
    while (st <= en) {
        md = st + en >> 1, X = 0, Y = 0;
        for (int i = 1; i <= N; i++) {
            if ((md + A[i] - 1) / A[i] <= M)
                X += M - (md + A[i] - 1) / A[i];
            else
                Y += (md - A[i] * M + B[i] - 1) / B[i];
        }
        if (Y <= X)
            st = md + 1, ans = md;
        else
            en = md - 1;
    }

    cout << ans << '\n';

    return 0;
}