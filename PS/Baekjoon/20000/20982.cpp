#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

int A[MAX], B[MAX];

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, K, res = 0, st, en, mid, cnt = 0, X, Y, Z;
    bool flag;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    st = 1, en = 1000000000000000;
    while (st <= en) {
        mid = st + en >> 1, cnt = 0, X = 0, flag = true;
        for (int i = N; i >= 1; i--) {
            if (B[i] > X)
                Z = B[i] - X, X = 0;
            else
                Z = 0, X -= B[i];
            if (mid <= A[i]) {
                flag = false;
                break;
            }
            Y = (mid - A[i] + Z - 1) / (mid - A[i]);
            cnt += Y, X += Y * (mid - A[i]) - Z;
        }

        if (cnt <= K && flag)
            res = mid, en = mid - 1;
        else
            st = mid + 1;
    }

    cout << res << '\n';

    return 0;
}