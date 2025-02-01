#include <bits/stdc++.h>
#define int long long

#define MAX 300000
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

int N, A[MAX], B[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, res, st, en, mid, cnt;
    bool flag;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1, greater<int>());

    for (int i = 1; i <= N; i++)
        cin >> B[i];
    sort(B + 1, B + N + 1, greater<int>());

    for (int i = 1; i <= N; i++)
        cin >> C[i];
    sort(C + 1, C + N + 1, greater<int>());

    st = 3, en = INF;
    while (st <= en) {
        mid = st + en >> 1, cnt = 0;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N && i * j <= K; j++)
                for (int k = 1; k <= N && i * j * k <= K; k++) {
                    if (A[i] * B[j] + B[j] * C[k] + C[k] * A[i] < mid)
                        break;
                    cnt++;
                }

        if (cnt >= K)
            res = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    cout << res << '\n';

    return 0;
}