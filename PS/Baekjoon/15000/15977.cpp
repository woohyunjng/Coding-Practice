#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;
typedef array<int, 2> pr;

int P[4][MAX], V[2][MAX];
set<pr> dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, ans = 1, st, en, mid, X;
    vector<int> comp;
    set<pr>::iterator iter;

    cin >> M >> N;

    for (int i = 1; i <= M; i++) {
        comp.clear();
        for (int j = 1; j <= N; j++)
            cin >> P[i][j], comp.push_back(P[i][j]);
        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (int j = 1; j <= N; j++)
            P[i][j] = lower_bound(comp.begin(), comp.end(), P[i][j]) - comp.begin() + 1;
    }

    for (int i = 1; i <= N; i++)
        V[0][P[1][i]] = P[2][i], V[1][P[1][i]] = P[3][i];

    for (int i = 1; i <= N; i++) {
        st = 1, en = ans, X = 0;
        while (st <= en) {
            mid = st + en >> 1;
            iter = dp[mid].lower_bound({V[0][i], V[1][i]});
            if (iter != dp[mid].begin() && (*prev(iter))[1] <= V[1][i])
                st = mid + 1, X = mid;
            else
                en = mid - 1;
        }
        iter = dp[X + 1].lower_bound({V[0][i], V[1][i]});
        while (iter != dp[X + 1].end() && (*iter)[1] >= V[1][i])
            dp[X + 1].erase(iter), iter = dp[X + 1].lower_bound({V[0][i], V[1][i]});
        dp[X + 1].insert({V[0][i], V[1][i]});
        ans = max(ans, X + 1);
    }

    cout << ans << '\n';

    return 0;
}