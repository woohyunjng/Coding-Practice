#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int A[MAX];
map<int, int> sm, cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, res = 0, val = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], res += (N + 1) * A[i];

    for (int i = 0; i < 24; i++) {
        X = 1 << (i + 1), val = 0;
        sm.clear(), cnt.clear();

        for (int j = 1; j <= N; j++) {
            sm[A[j] % X] += A[j], cnt[A[j] % X]++;
            Y = (X - A[j] % X) % X;
            if (cnt.count(Y))
                val += A[j] * cnt[Y] + sm[Y];
        }
        res -= val / X;
    }

    cout << res << '\n';

    return 0;
}