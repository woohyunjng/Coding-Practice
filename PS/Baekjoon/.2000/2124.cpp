#include <bits/stdc++.h>
#define int long long

#define MOD 1000000000000000000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<vector<int>> cond;
map<vector<int>, int> dp[21];

int A, B, C;

void dfs(vector<int> &X) {
    if (X.size() == C) {
        cond.push_back(X);
        return;
    }

    for (int i = (X.empty() ? 0 : X.back()); i <= B; i++) {
        X.push_back(i);
        dfs(X);
        X.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = 0;
    bool check;

    cin >> A >> B >> C;

    vector<int> empt;

    dfs(empt);

    for (vector<int> i : cond)
        dp[1][i] = 1;

    for (int i = 2; i <= A; i++) {
        for (vector<int> j : cond) {
            for (vector<int> k : cond) {
                check = true;
                for (int l = 0; l < C; l++)
                    check = check && (j[l] <= k[l]);
                if (check)
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    for (vector<int> i : cond)
        res = (res + dp[A][i]) % MOD;

    cout << res;

    return 0;
}