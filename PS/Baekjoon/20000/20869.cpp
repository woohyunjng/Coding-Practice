#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;
const int INF = 4'000'000'000'000;

int in[MAX];
double dp[MAX];

vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;
    double st = 0, en = 2000000, mid, ans = 0;

    queue<int> q;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z});
    }

    while (en - st > 1e-12) {
        mid = (st + en) / 2;

        for (int i = 1; i <= N; i++)
            dp[i] = -INF, in[i] = 0;
        for (int i = 1; i <= N; i++) {
            if (i != 1 && !in[i])
                continue;
            for (pr j : adj[i])
                in[j[0]]++;
        }

        q.push(1), dp[1] = 0;
        while (!q.empty()) {
            X = q.front(), q.pop();
            for (pr i : adj[X]) {
                dp[i[0]] = max(dp[i[0]], dp[X] + i[1] - mid);
                if (--in[i[0]] == 0)
                    q.push(i[0]);
            }
        }

        if (dp[N] >= 0)
            st = mid, ans = mid;
        else
            en = mid;
    }

    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}