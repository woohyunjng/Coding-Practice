#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 200000;
const int MAX_LOG = 20;

vector<tp> arr[MAX_LOG];
int uf[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, C, K, X, ans = 0;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V >> C >> K, X = 0;
        while ((1 << (X + 1)) <= K)
            X++;
        if ((1 << X) == K)
            arr[X].push_back({U, V, C});
        else
            arr[X].push_back({U, V, C}), arr[X].push_back({(U + K - (1 << X)) % N, (V + K - (1 << X)) % N, C + K - (1 << X)});
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++)
            uf[j] = j;
        sort(arr[i].begin(), arr[i].end(), [](tp x, tp y) { return x[2] < y[2]; });

        for (tp j : arr[i]) {
            if (find(j[0]) == find(j[1]))
                continue;
            uni(j[0], j[1]);
            if (i == 0)
                ans += j[2];
            else {
                arr[i - 1].push_back({j[0], j[1], j[2]});
                arr[i - 1].push_back({(j[0] + (1 << (i - 1))) % N, (j[1] + (1 << (i - 1))) % N, j[2] + (1 << (i - 1))});
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (find(i) != find(0))
            ans = -1;

    cout << ans << '\n';

    return 0;
}