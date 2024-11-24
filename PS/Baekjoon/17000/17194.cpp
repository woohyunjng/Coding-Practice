#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX][2], inv[MAX][2], cnt[MAX][2][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = INF, X, tr = 0;
    cin >> N;

    A[0][0] = A[0][1] = -1;

    for (int i = 1; i <= N; i++)
        cin >> A[i][0], cnt[i][0][0] = cnt[i - 1][0][0] + (A[i][0] == 0), cnt[i][0][1] = cnt[i - 1][0][1] + (A[i][0] == 1);
    for (int i = 1; i <= N; i++)
        inv[i][0] = inv[i - 1][0] + (A[i][0] == 0) * cnt[i][0][1];

    for (int i = 1; i <= N; i++)
        cin >> A[i][1];
    for (int i = N; i >= 0; i--) {
        cnt[i][1][0] = cnt[i + 1][1][0] + (A[i][1] == 0), cnt[i][1][1] = cnt[i + 1][1][1] + (A[i][1] == 1);
        inv[i][1] = inv[i + 1][1] + (A[i][1] == 1) * cnt[i][1][0];
    }

    X = N;
    for (int i = 0; i <= N && X >= 1; i++) {
        if (A[i][1] == 0) {
            while (X >= 1 && A[X][0] == 0)
                X--;
            tr += N + i - X;
            X--;
        }

        res = min(res, tr + abs(inv[i + 1][1] + cnt[i + 1][1][0] * i - (inv[X][0] + cnt[X][0][1] * (N - X))));
    }

    X = 1, tr = 0;

    for (int i = N; i >= 1 && X <= N; i--) {
        if (A[i][0] == 0) {
            while (X <= N && A[X][1] == 0)
                X++;
            tr += N + X - i;
            X++;
        }

        res = min(res, tr + abs(inv[i - 1][0] - inv[X][1]));
    }

    cout << res << '\n';

    return 0;
}