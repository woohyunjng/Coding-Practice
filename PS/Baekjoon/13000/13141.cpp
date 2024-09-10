#include <bits/stdc++.h>
#define int long long

#define MAX 210
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int min_dis[MAX][MAX], max_dis[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, res = INF, val;
    cin >> N >> M;

    fill(min_dis[0], min_dis[MAX], INF);
    for (int i = 1; i <= N; i++)
        min_dis[i][i] = 0;

    while (M--) {
        cin >> A >> B >> C;
        min_dis[A][B] = min_dis[B][A] = min(min_dis[A][B], C);
        max_dis[A][B] = max_dis[B][A] = max(max_dis[A][B], C);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                min_dis[j][k] = min(min_dis[j][k], min_dis[j][i] + min_dis[i][k]);

    for (int i = 1; i <= N; i++) {
        val = 0;

        for (int j = 1; j <= N; j++) {
            for (int k = 1; k < j; k++) {
                if (max_dis[j][k] == 0)
                    continue;
                val = max(val, min_dis[i][k] + min_dis[i][j] + max_dis[j][k]);
            }
        }

        for (int j = 1; j <= N; j++) {
            if (max_dis[j][j] == 0)
                continue;
            val = max(val, min_dis[i][j] * 2 + max_dis[j][j]);
        }

        res = min(res, val);
    }

    cout << fixed << setprecision(1);
    cout << (double)res / 2;

    return 0;
}