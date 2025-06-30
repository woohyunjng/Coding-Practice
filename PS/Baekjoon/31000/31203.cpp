#include <bits/stdc++.h>
using namespace std;

const int MAX = 9;

typedef pair<bool, vector<int>> act; // false -> D, true -> R

int N, A[MAX][MAX], S[MAX][MAX];
bool chk[MAX][MAX], bchk[MAX][MAX];

bool dfs(int R, int C) {
    for (int i = 0; i < N; i++) {
        if (bchk[R][i] || chk[i][A[R][C] / N])
            continue;
        bchk[R][i] = true, chk[i][A[R][C] / N] = true, S[R][i] = A[R][C];
        if ((R == N - 1 && C == N - 1) || dfs(R + (C == N - 1), (C + 1) % N))
            return true;
        bchk[R][i] = false, chk[i][A[R][C] / N] = false;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    bool flag;

    vector<int> val;
    vector<act> ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i % N][j];

    for (int i = 0; i < N; i++)
        chk[i][A[0][i] / N] = true, S[0][i] = A[0][i];

    dfs(1, 0);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++)
            val.push_back(S[i][j]);
        for (int j = 0; j < N; j++)
            A[i][j] = S[i][j];
        ans.push_back({false, val}), val.clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            val.push_back(A[j][i]);
        sort(val.begin(), val.end(), [&](int x, int y) { return x / N < y / N; });
        for (int j = 0; j < N; j++)
            A[j][i] = val[j];
        ans.push_back({true, val}), val.clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            val.push_back(A[i][j]);
        sort(val.begin(), val.end(), [&](int x, int y) { return x % N < y % N; });
        for (int j = 0; j < N; j++)
            A[i][j] = val[j];
        ans.push_back({false, val}), val.clear();
    }

    cout << ans.size() << '\n';
    for (act i : ans) {
        cout << (i.first ? 'R' : 'D') << ' ';
        for (int j : i.second)
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}