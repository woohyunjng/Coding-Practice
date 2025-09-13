#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;
const int INF = 100000000;

vector<pr> adj[MAX];
vector<int> arr[MAX];
map<pr, int> mp;

int A[MAX], V[MAX], depth[MAX], vst[MAX], D[MAX], ans = 0, val;

bool ans_chk = true;

void dfs(int node, int t, int k) {
    vst[node] = k, D[node] = t, val += t;
    if (V[node] != -1 && V[node] != t)
        val = INF;

    for (pr i : adj[node]) {
        if (vst[i[0]] != k)
            depth[i[0]] = depth[node] + 1, dfs(i[0], (i[1] + 3 - t) % 3, k);
        else if (depth[i[0]] < depth[node])
            continue;
        else
            ans_chk &= (D[node] + D[i[0]]) % 3 == i[1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L, B, K, X, Y;
    string S;

    cin >> L >> B >> S;
    for (int i = 1; i <= L; i++)
        A[i] = (S[i - 1] == 'R' ? 0 : (S[i - 1] == 'G' ? 2 : 1));

    for (int i = 1; i <= B; i++) {
        cin >> K, V[i] = -1, vst[i] = -1;
        while (K--)
            cin >> X, arr[X].push_back(i);
    }

    for (int i = 1; i <= L; i++) {
        if (arr[i].empty())
            ans_chk &= A[i] == 0;
        else if (arr[i].size() == 1)
            ans_chk &= V[arr[i][0]] == -1 || V[arr[i][0]] == A[i], V[arr[i][0]] = A[i];
        else {
            X = arr[i][0], Y = arr[i][1];
            if (mp.count({X, Y}))
                ans_chk &= mp[{X, Y}] == A[i];
            else {
                mp[{X, Y}] = A[i];
                adj[X].push_back({Y, A[i]}), adj[Y].push_back({X, A[i]});
            }
        }
    }

    for (int i = 1; i <= B; i++) {
        if (vst[i] != -1)
            continue;
        X = INF;
        for (int j = 0; j < 3; j++)
            val = 0, dfs(i, j, j), X = min(X, val);
        ans += X, ans_chk &= X < INF;
    }

    if (!ans_chk)
        cout << "impossible" << '\n';
    else
        cout << ans << '\n';

    return 0;
}