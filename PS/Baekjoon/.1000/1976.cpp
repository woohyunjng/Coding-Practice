#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;

int uf[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    vector<int> arr;
    bool ans = true;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        uf[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> X;
            if (X)
                uni(i, j);
        }

    for (int i = 0; i < M; i++)
        cin >> X, arr.push_back(X);

    for (int i = 1; i < M; i++)
        ans &= find(arr[i]) == find(arr[0]);

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}