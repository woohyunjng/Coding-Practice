#include <bits/stdc++.h>
using namespace std;

int N;
string S;

void dfs(int node) {
    if (node > N)
        return;
    dfs(node << 1);
    cout << S[node - 1] << ' ';
    dfs(node << 1 | 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> S;

    dfs(1);
    cout << '\n';

    return 0;
}