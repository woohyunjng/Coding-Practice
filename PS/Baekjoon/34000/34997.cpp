#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 1218;

int A[MAX][MAX], DS[4][MAX][MAX], K[MAX * MAX],
    RPS[MAX], RSS[MAX], CPS[MAX], CSS[MAX];
pr V[MAX * MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, D, S, R[2], C[2], ans, AL = 0, X;
    vector<int> comp;

    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j], comp.push_back(A[i][j]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= S; i++)
        V[i][0] = {MAX + 1, MAX + 1}, V[i][1] = {0, 0};

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            A[i][j] = lower_bound(comp.begin(), comp.end(), A[i][j]) - comp.begin() + 1;
            V[A[i][j]][0] = min(V[A[i][j]][0], pr{i, j}), V[A[i][j]][1] = max(V[A[i][j]][1], pr{i, j});
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> X, K[A[i][j]] = X;

    for (int i = 1; i <= S; i++) {
        AL += K[i];
        RPS[V[i][1][0]] += K[i], RSS[V[i][0][0]] += K[i];
        CPS[V[i][1][1]] += K[i], CSS[V[i][0][1]] += K[i];
        DS[0][V[i][1][0]][V[i][1][1]] += K[i], DS[1][V[i][0][0]][V[i][1][1]] += K[i];
        DS[2][V[i][1][0]][V[i][0][1]] += K[i], DS[3][V[i][0][0]][V[i][0][1]] += K[i];
    }

    for (int i = 1; i <= N; i++)
        RPS[i] += RPS[i - 1];
    for (int i = N; i >= 1; i--)
        RSS[i] += RSS[i + 1];
    for (int i = 1; i <= M; i++)
        CPS[i] += CPS[i - 1];
    for (int i = M; i >= 1; i--)
        CSS[i] += CSS[i + 1];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            DS[0][i][j] += DS[0][i - 1][j] + DS[0][i][j - 1] - DS[0][i - 1][j - 1];
    for (int i = N; i >= 1; i--)
        for (int j = 1; j <= M; j++)
            DS[1][i][j] += DS[1][i + 1][j] + DS[1][i][j - 1] - DS[1][i + 1][j - 1];
    for (int i = 1; i <= N; i++)
        for (int j = M; j >= 1; j--)
            DS[2][i][j] += DS[2][i - 1][j] + DS[2][i][j + 1] - DS[2][i - 1][j + 1];
    for (int i = N; i >= 1; i--)
        for (int j = M; j >= 1; j--)
            DS[3][i][j] += DS[3][i + 1][j] + DS[3][i][j + 1] - DS[3][i + 1][j + 1];

    for (int i = 1; i <= D; i++) {
        cin >> R[0] >> C[0] >> R[1] >> C[1], ans = AL;
        ans -= RPS[R[0] - 1] + RSS[R[1] + 1] + CPS[C[0] - 1] + CSS[C[1] + 1];
        ans += DS[0][R[0] - 1][C[0] - 1] + DS[1][R[1] + 1][C[0] - 1] + DS[2][R[0] - 1][C[1] + 1] + DS[3][R[1] + 1][C[1] + 1];
        cout << ans << '\n';
    }

    return 0;
}