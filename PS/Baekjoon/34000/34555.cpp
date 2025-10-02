#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, R;

    cin >> N, L = 1, R = N;
    for (int i = 0; L <= R; i++) {
        if (i & 1)
            ans[i] = L++;
        else
            ans[i] = R--;
    }

    for (int i = N - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}