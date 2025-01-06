#include <bits/stdc++.h>
#define int long long

#define MAX 300100
using namespace std;

int S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, Y = 0, res = 0;
    cin >> N;

    for (int i = 1; i <= N * 3; i++)
        cin >> S[i];
    sort(S + 1, S + N * 3 + 1);

    X = 1, Y = 3 * N;
    while (X <= Y) {
        res += S[Y - 1];
        Y -= 2, X++;
    }

    cout << res << '\n';

    return 0;
}