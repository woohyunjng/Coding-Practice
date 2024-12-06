#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int X[MAX], Y[MAX], dis[MAX][2];
vector<pr> arr[2][MAX], adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, XL, YL, XB, YB, K, res;
    tp P;
    vector<int> Xcomp, Ycomp;
    cin >> N >> XL >> YL >> XB >> YB;

    X[0] = XL, Y[0] = YL, X[N + 1] = XB, Y[N + 1] = YB;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        Xcomp.push_back(X[i]), Ycomp.push_back(Y[i]);
    }
    Xcomp.push_back(XL), Xcomp.push_back(XB), Ycomp.push_back(YL), Ycomp.push_back(YB);
    sort(Xcomp.begin(), Xcomp.end()), sort(Ycomp.begin(), Ycomp.end());

    for (int i = 0; i <= N + 1; i++) {
        X[i] = lower_bound(Xcomp.begin(), Xcomp.end(), X[i]) - Xcomp.begin() + 1;
        Y[i] = lower_bound(Ycomp.begin(), Ycomp.end(), Y[i]) - Ycomp.begin() + 1;
        arr[0][X[i]].push_back({Y[i], i});
        arr[1][Y[i]].push_back({X[i], i});
    }

    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= N + 2; j++)
            sort(arr[i][j].begin(), arr[i][j].end());

    for (int i = 0; i <= N + 1; i++) {
        K = lower_bound(arr[0][X[i]].begin(), arr[0][X[i]].end(), pr(Y[i], i)) - arr[0][X[i]].begin();
        if (K < arr[0][X[i]].size() - 1)
            adj[i].push_back({arr[0][X[i]][K + 1].second, 1});
        if (K)
            adj[i].push_back({arr[0][X[i]][K - 1].second, 1});

        K = lower_bound(arr[1][Y[i]].begin(), arr[1][Y[i]].end(), pr(X[i], i)) - arr[1][Y[i]].begin();
        if (K < arr[1][Y[i]].size() - 1)
            adj[i].push_back({arr[1][Y[i]][K + 1].second, 0});
        if (K)
            adj[i].push_back({arr[1][Y[i]][K - 1].second, 0});
    }

    priority_queue<tp, vector<tp>, greater<tp>> q;

    fill(&dis[0][0], &dis[N + 2][2], INF);
    dis[0][0] = dis[0][1] = 0;
    q.push({0, 0, 0}), q.push({0, 0, 1});

    while (!q.empty()) {
        P = q.top(), q.pop();
        if (dis[P[1]][P[2]] < P[0])
            continue;

        for (pr i : adj[P[1]]) {
            if (dis[i.first][i.second] > P[0] + (i.second != P[2])) {
                dis[i.first][i.second] = P[0] + (i.second != P[2]);
                q.push({dis[i.first][i.second], i.first, i.second});
            }
        }
    }

    res = min(dis[N + 1][0], dis[N + 1][1]);
    cout << (res == INF ? -1 : res) << '\n';

    return 0;
}