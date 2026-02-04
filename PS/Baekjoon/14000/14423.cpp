#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000001;

int C[MAX], B[MAX], V[2][MAX], F[2][MAX], MX[2];
vector<int> val[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, ans;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> C[i], B[C[i]]++;

    for (int x = 0; x < 2; x++) {
        if (x == 1 && C[0] != C[1])
            val[x][C[0]].push_back(1), val[x][C[1]].push_back(0);

        S = x + 1;
        for (int i = 0; i <= x; i++)
            V[x][C[i]]++;

        while (S < N) {
            if (S != N - 1 && C[S] != C[S + 1])
                val[x][C[S]].push_back(S + 1), val[x][C[S + 1]].push_back(S);
            for (int i = S; i < min(S + 2, N); i++)
                V[x][C[i]]++;
            S += 2;
        }

        for (int i = 1; i <= M; i++)
            F[x][V[x][i]]++, MX[x] = max(MX[x], V[x][i]);
    }

    for (int i = 1; i <= M; i++) {
        ans = N - B[i];
        for (int x = 0; x < 2; x++) {
            for (int j = 1; j <= B[i]; j++) {
                F[x][V[x][i]]--, V[x][i]--;
                F[x][V[x][i]]++, MX[x] -= F[x][MX[x]] == 0;
            }
            for (int j : val[x][i]) {
                F[x][V[x][C[j]]]--, V[x][C[j]]--;
                F[x][V[x][C[j]]]++, MX[x] -= F[x][MX[x]] == 0;
            }

            ans = min(ans, N - B[i] - MX[x]);

            for (int j = 1; j <= B[i]; j++) {
                F[x][V[x][i]]--, V[x][i]++;
                F[x][V[x][i]]++, MX[x] += F[x][MX[x] + 1] > 0;
            }
            for (int j : val[x][i]) {
                F[x][V[x][C[j]]]--, V[x][C[j]]++;
                F[x][V[x][C[j]]]++, MX[x] += F[x][MX[x] + 1] > 0;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}