#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007

using namespace std;

int D[MAX];
vector<int> adj[MAX], dis[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, res = 1;
    vector<int> arr;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> D[i], arr.push_back(i), dis[D[i]].push_back(i);
        if (i > 1 && D[i] == 0)
            res = 0;
    }

    sort(arr.begin(), arr.end(), [&](int X, int Y) { return D[X] < D[Y]; });

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cout << res << '\n';

    return 0;
}