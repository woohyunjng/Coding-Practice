#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[3][MAX], lst[3], val[3][MAX];
pr parent[MAX];
vector<pr> adj[MAX];
bool vst[MAX];

void solve() {
    int N, K;
    vector<pr> ans;

    cin >> N;

    queue<int> q;

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> P[i][j];
            val[i][P[i][j]] = j;
        }
        lst[i] = 1;
    }

    q.push(1), vst[1] = true;

    while (!q.empty()) {
        K = q.front(), q.pop();

        for (int i = 0; i < 3; i++) {
            for (int j = lst[i]; j < P[i][K]; j++) {
                if (vst[val[i][j]] || val[i][j] < K)
                    continue;
                adj[K].push_back({val[i][j], i});
                q.push(val[i][j]), vst[val[i][j]] = true;
            }
            lst[i] = max(lst[i], P[i][K] + 1);
        }
    }

    q.push(1);
    while (!q.empty()) {
        K = q.front(), q.pop();

        for (auto [i, j] : adj[K]) {
            parent[i] = {K, j};
            q.push(i);
        }
    }

    if (parent[N].first == 0)
        cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';

        K = N;

        while (K != 1) {
            ans.push_back({K, parent[K].second});
            K = parent[K].first;
        }

        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());

        for (pr i : ans)
            cout << (i.second == 0 ? 'q' : (i.second == 1 ? 'k' : 'j')) << ' ' << i.first << '\n';
    }

    for (int i = 1; i <= N; i++) {
        adj[i].clear();
        vst[i] = false;
        parent[i] = {0, 0};
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}