#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int W[MAX], L[MAX], R[MAX], val[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, S, T, ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> W[i];
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i];

    for (int i = 0; i <= N * 2 + 1; i++)
        val[i][0] = val[i][1] = INF;

    for (int i = 1; i <= N; i++) {
        val[R[i]][0] = min(val[R[i]][0], W[i]);
        val[L[i]][1] = min(val[L[i]][1], W[i]);
    }

    for (int i = 2; i <= N * 2; i++)
        val[i][0] = min(val[i][0], val[i - 1][0]);
    for (int i = N * 2 - 1; i >= 1; i--)
        val[i][1] = min(val[i][1], val[i + 1][1]);

    cin >> Q;
    while (Q--) {
        cin >> S >> T;
        if (L[S] > L[T])
            swap(S, T);

        ans = W[S] + W[T] + min(val[min(L[S], L[T]) - 1][0], val[max(R[S], R[T]) + 1][1]);

        if (R[S] < L[T])
            ans = W[S] + W[T];
        else if (L[S] <= L[T] && R[T] <= R[S])
            ans = ans;
        else
            ans = min(ans, W[S] + W[T] + val[R[S] + 1][1] + val[L[T] - 1][0]);

        ans = ans >= INF ? -1 : ans;
        cout << ans << '\n';
    }

    return 0;
}