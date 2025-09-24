#include <bits/stdc++.h>
using namespace std;

int V[13];

void dfs(int N) {
    if (N == 0) {
        cout << '-';
        return;
    }

    dfs(N - 1);
    for (int i = 0; i < V[N - 1]; i++)
        cout << ' ';
    dfs(N - 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    V[0] = 1;
    for (int i = 1; i <= 12; i++)
        V[i] = V[i - 1] * 3;

    int N;

    while (cin >> N)
        dfs(N), cout << '\n';

    return 0;
}