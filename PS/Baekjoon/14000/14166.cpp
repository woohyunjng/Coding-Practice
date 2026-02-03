#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int N, K, S[MAX], V[MAX][10], X, Y;
vector<int> arr;

void dfs(int node, int cnt, int val, int mx) {
    if (val > mx || X == K)
        return;
    X++, Y += val;
    if (cnt + 1 < S[arr[node]])
        dfs(node, cnt + 1, val + V[arr[node]][cnt + 1] - V[arr[node]][cnt], mx);
    for (int i = node + 1; i < arr.size() && val + V[arr[i]][1] <= mx && X < K; i++)
        dfs(i, 1, val + V[arr[i]][1], mx);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int DF = 0, ans;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        for (int j = 0; j < S[i]; j++)
            cin >> V[i][j];
        sort(V[i], V[i] + S[i]), DF += V[i][0];
        for (int j = S[i] - 1; j >= 0; j--)
            V[i][j] -= V[i][0];
        if (S[i] > 1)
            arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return V[x][1] < V[y][1]; });

    for (int st = 1, en = 1e15, md; st <= en;) {
        md = st + en >> 1, X = Y = 0;
        dfs(0, 0, DF, md - 1);
        if (X < K)
            ans = md, st = md + 1;
        else
            en = md - 1;
    }

    X = Y = 0, dfs(0, 0, DF, ans - 1);
    cout << Y + (K - X) * ans << '\n';

    return 0;
}