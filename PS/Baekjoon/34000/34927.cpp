#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

int W[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> W[i];
    sort(W + 1, W + N + 1);

    for (int i = 1; i <= N; i++) {
        if (X <= W[i])
            ans++, X += W[i];
    }

    cout << ans << '\n';

    return 0;
}