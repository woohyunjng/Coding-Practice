#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr arr[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 0, st, en, md, A, B, C, D;
    cin >> N >> X;

    for (int i = 1; i <= N; i++)
        cin >> arr[i][0].first >> arr[i][0].second >> arr[i][1].first >> arr[i][1].second;

    st = 0, en = 1e9 + 1;
    while (st <= en) {
        md = st + en >> 1, A = 0;

        for (int i = 1; i <= N; i++) {
            B = INF;

            for (int j = 0; j <= arr[i][1].first; j++) {
                C = (md - j * arr[i][0].first + arr[i][1].first - 1) / arr[i][1].first;
                if (C >= 0)
                    B = min(B, j * arr[i][0].second + C * arr[i][1].second);
            }

            for (int j = 0; j <= arr[i][0].first; j++) {
                C = (md - j * arr[i][1].first + arr[i][0].first - 1) / arr[i][0].first;
                if (C >= 0)
                    B = min(B, j * arr[i][1].second + C * arr[i][0].second);
            }

            A += B;
        }

        if (A <= X) {
            res = md;
            st = md + 1;
        } else
            en = md - 1;
    }

    cout << res;

    return 0;
}