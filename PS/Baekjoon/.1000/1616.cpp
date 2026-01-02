#include <bits/stdc++.h>
using namespace std;

int X[10'000'001];

int K, M, V, C = 0;

void dfs(int node) {
    while (X[node] < K)
        dfs((node % V) * K + (X[node]++));
    if (C > 0)
        cout << node % K << ' ', C--;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> K >> M, V = 1;
    if (M == 1) {
        for (int i = 0; i < K; i++)
            cout << i << ' ';
        return 0;
    }

    for (int i = 1; i + 1 < M; i++)
        V *= K;
    C = V * K * K;

    dfs(0);

    return 0;
}