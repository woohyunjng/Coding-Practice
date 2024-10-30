#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = INF, res_num = -1, X, Y, SX, SY, EX, EY, N, M, A, B, val;

    cin >> N;
    cin >> SX >> SY >> EX >> EY;

    for (int i = 1; i <= N; i++) {
        val = 0;

        cin >> M;
        X = SX, Y = SY;

        while (M--) {
            cin >> A >> B;
            val += abs(A - X) + abs(B - Y);
            X = A, Y = B;
        }
        val += abs(EX - X) + abs(EY - Y);

        if (val < res)
            res = val, res_num = i;
    }

    cout << res_num;

    return 0;
}