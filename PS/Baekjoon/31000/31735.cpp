#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 100001;
const int BUCKET = 100;
const int MAX_LOG = 20;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<tp> V[MAX];

pr sparse[MAX][MAX_LOG];
int S[MAX], E[MAX], D[MAX], K[MAX], P[1040][MAX], G[MAX], num[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, Q, M, L, R, A, B, X, ans, val;
    vector<pr> arr, tmp;

    cin >> N >> T, X = 0;
    for (int i = 1; i < N; i++) {
        cin >> M, arr.clear();
        while (M--) {
            cin >> A >> B;
            arr.push_back({A, B});
        }
        sort(arr.rbegin(), arr.rend());

        for (pr j : arr) {
            if (!V[i].empty() && V[i].back()[1] <= j[1])
                continue;
            V[i].push_back({j[0], j[1], 0});
        }
        reverse(V[i].begin(), V[i].end());

        K[i] = X + 1;
        for (tp &j : V[i])
            j[2] = ++X, S[X] = j[0], E[X] = j[1], D[X] = i;
    }
    V[N].push_back({0, 0, 0});

    M = X, D[0] = N;
    for (int i = 1; i <= M; i++) {
        if (D[i] == N - 1) {
            sparse[i][0] = {0, E[i] - S[i]};
            continue;
        }

        X = lower_bound(V[D[i] + 1].begin(), V[D[i] + 1].end(), (tp){E[i], 0, 0}) - V[D[i] + 1].begin();
        if (X == V[D[i] + 1].size())
            sparse[i][0] = {V[D[i] + 1][0][2], T - S[i] + V[D[i] + 1][0][0]};
        else
            sparse[i][0] = {V[D[i] + 1][X][2], V[D[i] + 1][X][0] - S[i]};
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= M; j++) {
            sparse[j][i][0] = sparse[sparse[j][i - 1][0]][i - 1][0];
            sparse[j][i][1] = sparse[sparse[j][i - 1][0]][i - 1][1] + sparse[j][i - 1][1];
        }

    A = 0;
    for (int i = 1; i < N; i++) {
        if (V[i].size() <= BUCKET)
            continue;
        num[i] = ++A, arr.clear();
        for (tp j : V[i])
            arr.push_back({j[2]});
        for (int j = i + 1; j <= N; j++) {
            for (tp k : V[j])
                G[k[2]] = INF;
            P[A][j] = INF;
            for (pr k : arr) {
                P[A][j] = min(P[A][j], k[1] + E[k[0]] - S[k[0]]);
                G[sparse[k[0]][0][0]] = min(G[sparse[k[0]][0][0]], k[1] + sparse[k[0]][0][1]);
            }
            for (tp k : V[j])
                tmp.push_back({k[2], G[k[2]]});
            arr = tmp, tmp.clear();
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> L >> R, ans = INF;
        if (V[L].size() <= BUCKET) {
            for (int i = 0; i < V[L].size(); i++) {
                val = 0, X = V[L][i][2];
                for (int j = MAX_LOG - 1; j >= 0; j--) {
                    if (D[sparse[X][j][0]] < R) {
                        val += sparse[X][j][1];
                        X = sparse[X][j][0];
                    }
                }
                if (D[X] < R)
                    val += E[X] - S[X];
                ans = min(ans, val);
            }
        } else
            ans = P[num[L]][R];
        cout << ans << '\n';
    }

    return 0;
}