#include <bits/stdc++.h>
#define int long long

#define MAX 110
using namespace std;

int T[MAX], L[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, res = 0;
    cin >> N >> D;

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> L[i];

    for (int i = 1; i <= D; i++) {
        res = 0;
        for (int j = 1; j <= N; j++)
            res = max(res, T[j] * (L[j] + i));
        cout << res << '\n';
    }

    return 0;
}