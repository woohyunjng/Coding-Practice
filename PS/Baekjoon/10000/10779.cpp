#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;
const int MAX_LOG = 20;

int A[MAX], L[MAX], par[MAX][MAX_LOG];

int get_par(int X, int K) {
    if (L[X] <= K)
        return X;
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (L[par[X][i]] > K)
            X = par[X][i];
    return par[X][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], L[i] = max(0, -A[i]);
        if (L[i] > 0) {
            par[i][0] = get_par(get_par(i - 1, L[i] - 1) - 1, L[i] - 1);
            for (int j = 1; j < MAX_LOG; j++)
                par[i][j] = par[par[i][j - 1]][j - 1];
        }
        cout << A[get_par(i, 0)] << '\n';
    }
}