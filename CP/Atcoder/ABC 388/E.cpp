#include <bits/stdc++.h>
#define int long long

#define MAX 500100

using namespace std;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X, st, en, mid;
    bool flag;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    st = 1, en = N / 2;
    while (st <= en) {
        mid = st + en >> 1, X = 1, flag = false;
        for (int i = mid + 1; i <= N; i++) {
            if (A[i] >= A[X] * 2)
                X++;
        }
        flag = X > mid;
        if (flag)
            res = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    cout << res << '\n';

    return 0;
}