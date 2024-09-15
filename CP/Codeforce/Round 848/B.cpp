#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], A[MAX], pos[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, D, res = INF, val;
    cin >> T;

    while (T--) {
        cin >> N >> M >> D;
        for (int i = 1; i <= N; i++) {
            cin >> P[i];
            pos[P[i]] = i;
        }

        for (int i = 1; i <= M; i++)
            cin >> A[i];

        res = INF;
        for (int i = 1; i < M; i++) {
            if (pos[A[i]] > pos[A[i + 1]])
                val = 0;
            else if (pos[A[i]] + D < pos[A[i + 1]])
                val = 0;
            else {
                val = pos[A[i + 1]] - pos[A[i]];
                if (N - 1 > D)
                    val = min(val, D + 1 - (pos[A[i + 1]] - pos[A[i]]));
            }
            res = min(res, val);
        }

        cout << res << '\n';
    }

    return 0;
}