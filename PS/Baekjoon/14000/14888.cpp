#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 11;
const int INF = 2e9;

int N, ans_max = -INF, ans_min = INF, A[MAX], C[4];

void dfs(int x, int v) {
    if (x == N) {
        ans_max = max(ans_max, v);
        ans_min = min(ans_min, v);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (C[i] == 0)
            continue;
        C[i]--;
        if (i == 0)
            dfs(x + 1, v + A[x]);
        else if (i == 1)
            dfs(x + 1, v - A[x]);
        else if (i == 2)
            dfs(x + 1, v * A[x]);
        else
            dfs(x + 1, v / A[x]);
        C[i]++;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < 4; i++)
        cin >> C[i];

    dfs(1, A[0]);

    cout << ans_max << '\n'
         << ans_min << '\n';

    return 0;
}