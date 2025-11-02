#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 1001;

int T[MAX], X[MAX], Y[MAX], ans;
bool chk[MAX];
vector<int> adj[MAX];
vector<pr> val[MAX][MAX];

void dfs(int node) {
    chk[node] = true, ans++;
    for (int i : adj[node])
        if (!chk[i])
            dfs(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, SX, SY;
    char C;

    vector<int> compX, compY;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C >> X[i] >> Y[i], T[i] = C == 'N';
        compX.push_back(X[i]), compY.push_back(Y[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end()), SX = compX.size();
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), SY = compY.size();

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    for (int i = 0; i < N; i++) {
        X[i] = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin();
        Y[i] = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin();
        pq.push({0, X[i], Y[i], i});
    }

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (val[K[1]][K[2]].empty() || val[K[1]][K[2]].back()[0] == K[0])
            val[K[1]][K[2]].push_back({K[0], K[3]});
        else {
            for (pr i : val[K[1]][K[2]])
                adj[i[1]].push_back(K[3]);
            continue;
        }

        if (T[K[3]] && K[2] + 1 < SY)
            pq.push({K[0] + compY[K[2] + 1] - compY[K[2]], K[1], K[2] + 1, K[3]});
        else if (!T[K[3]] && K[1] + 1 < SX)
            pq.push({K[0] + compX[K[1] + 1] - compX[K[1]], K[1] + 1, K[2], K[3]});
    }

    for (int i = 0; i < N; i++) {
        fill(chk, chk + N, false);
        dfs(i), cout << ans - 1 << '\n', ans = 0;
    }

    return 0;
}