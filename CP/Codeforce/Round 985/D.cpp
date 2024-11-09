#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];

bool cur[MAX];

void solve() {
    int N, M, A, B;
    cin >> N >> M;

    vector<tp> res;

    while (M--) {
        cin >> A >> B;
        if (A > B)
            swap(A, B);

        if (A == 1) {
            cur[B] = !cur[B];
            continue;
        }

        res.push_back({1, A, B});
        cur[A] = !cur[A], cur[B] = !cur[B];
    }

    vector<int> X, Y;
    for (int i = 2; i <= N; i++) {
        if (cur[i])
            X.push_back(i);
        else
            Y.push_back(i);
    }

    if (!X.empty()) {
        A = X[0];
        for (int i : Y)
            res.push_back({1, A, i}), A = i;
    }

    cout << res.size() << '\n';
    for (tp i : res)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    for (int i = 1; i <= N; i++)
        adj[i].clear(), cur[i] = false;
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