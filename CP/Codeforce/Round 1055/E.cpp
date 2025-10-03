#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> query(vector<int> arr) {
    vector<int> res;
    int SZ, X;

    cout << "? " << arr.size() << ' ';
    for (int i : arr)
        cout << i << ' ';
    cout << '\n', cout.flush();

    cin >> SZ;
    while (SZ--)
        cin >> X, res.push_back(X);
    return res;
}

void answer(vector<int> arr) {
    cout << "! ";
    for (int i : arr)
        cout << i << ' ';
    cout << '\n', cout.flush();
}

vector<int> adj[MAX];
int dp[MAX], prv[MAX], in[MAX];

void solve() {
    int N, X, Y;
    vector<int> arr, val, ans, tmp;

    cin >> N;
    if (N == 1) {
        answer({1, 2});
        return;
    }

    for (int i = 1; i <= N * N + 1; i++)
        arr.push_back(i), adj[i].clear(), dp[i] = prv[i] = in[i] = 0;

    for (int i = 1; i <= N; i++) {
        val = query(arr);
        if (val.size() >= N + 1) {
            ans.clear();
            for (int j = 0; j < N + 1; j++)
                ans.push_back(val[j]);
            answer(ans);
            return;
        }

        X = -1;
        for (int j : arr) {
            if (X + 1 < val.size() && j == val[X + 1])
                X++;
            else
                adj[val[X]].push_back(j), in[j]++, tmp.push_back(j);
        }

        arr = tmp, tmp.clear();
    }

    queue<int> q;
    for (int i = 1; i <= N * N + 1; i++)
        if (in[i] == 0)
            q.push(i), dp[i] = 1;

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X]) {
            if (dp[i] < dp[X] + 1)
                dp[i] = dp[X] + 1, prv[i] = X;
            if (--in[i] == 0)
                q.push(i);
        }
    }

    for (int i = 1; i <= N * N + 1; i++)
        if (dp[i] > dp[X])
            X = i;

    while (X)
        ans.push_back(X), X = prv[X];
    reverse(ans.begin(), ans.end());

    while (ans.size() > N + 1)
        ans.pop_back();
    assert(ans.size() == (N + 1));

    answer(ans);
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}