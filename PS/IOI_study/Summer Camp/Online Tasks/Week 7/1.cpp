#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
using namespace std;

int X[MAX], A[MAX], event[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, res = 1, cur = 0;
    cin >> N >> C;

    for (int i = 1; i <= C; i++) {
        cin >> X[i], A[abs(X[i])] = i;
        if (X[i] < 0)
            event[-X[i] + 1]--, cur++;
        else
            event[X[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        cur += event[i];
        if (A[i] == 0)
            res = res * cur % MOD;
    }

    cout << res << '\n';

    return 0;
}