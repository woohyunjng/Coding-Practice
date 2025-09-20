#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

vector<int> adj[MAX];
int K, W[MAX], S[MAX], ans[MAX], V[MAX][3];

multiset<int> dfs(int node) {
    multiset<int> res, val;
    multiset<int>::reverse_iterator iter;
    vector<int> tmp;

    int X[2] = {0, 0};

    for (int i : adj[node]) {
        val = dfs(i);
        if (res.size() < val.size())
            swap(res, val), swap(S[node], S[i]);
        X[0] = val.size(), X[1] = res.size();

        if (X[0] * 2 >= K) {
            for (int j = 1; j <= X[0]; j++)
                V[j][0] = V[j - 1][0] + *val.rbegin(), val.erase(--val.end());
            for (int j = 1; j <= X[1]; j++)
                V[j][1] = V[j - 1][1] + *res.rbegin(), res.erase(--res.end());

            for (int j = 1; j <= X[1]; j++) {
                V[j][2] = V[j][1] + V[min({j, X[0], max(0ll, K - j)})][0];
                if (j <= X[0])
                    V[j][2] = max(V[j][2], V[j][0] + V[min({j, X[1], max(0ll, K - j)})][1]);
                if (V[j][2] < V[j - 1][2]) {
                    X[1] = j - 1;
                    break;
                }
            }

            res.clear(), S[node] = V[X[1]][2];
            for (int j = 1; j <= X[1]; j++)
                res.insert(V[j][2] - V[j - 1][2]);
        } else {
            iter = val.rbegin();
            for (int j = 1; j <= X[0]; j++)
                tmp.push_back(*iter + *res.rbegin()), ++iter, res.erase(--res.end());
            for (int j : tmp)
                res.insert(j);
            tmp.clear(), S[node] += S[i];

            for (int j = K - X[0] + 1; j <= X[1]; j++)
                tmp.push_back(*res.begin()), res.erase(res.begin()), S[node] -= tmp.back();
            reverse(tmp.begin(), tmp.end());

            for (int j = K - X[0] + 1; j <= X[1]; j++) {
                tmp[j - (K - X[0] + 1)] -= *val.begin(), val.erase(val.begin());
                if (tmp[j - (K - X[0] + 1)] >= 0)
                    res.insert(tmp[j - (K - X[0] + 1)]), S[node] += tmp[j - (K - X[0] + 1)];
                else
                    break;
            }
            tmp.clear();
        }
    }

    while (res.size() > K)
        S[node] -= *res.begin(), res.erase(res.begin());
    ans[node] = S[node];
    S[node] += W[node], res.insert(W[node]);
    while (res.size() > K)
        S[node] -= *res.begin(), res.erase(res.begin());

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N >> K;
    for (int i = 2; i <= N; i++)
        cin >> X >> W[i], adj[X].push_back(i);

    dfs(1);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}