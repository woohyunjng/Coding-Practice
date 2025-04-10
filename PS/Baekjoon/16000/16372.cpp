#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;

int parent[MAX];
vector<int> arr[MAX];

int find(int X) { return X == parent[X] ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    parent[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, X, Y, ans = 0;

    vector<int> comp;

    cin >> N >> M >> Q;

    for (int i = 1; i <= N + M; i++)
        parent[i] = i;

    while (Q--) {
        cin >> X >> Y;
        uni(X, Y + N), arr[X].push_back(Y + N), arr[Y + N].push_back(X);
    }

    for (int i = 1; i <= N + M; i++) {
        for (int j = 0; j + 1 < arr[i].size(); j++)
            uni(arr[i][j], arr[i][j + 1]);
    }

    for (int i = 1; i <= N + M; i++)
        if (find(i) == i)
            ans++;

    cout << ans - 1 << '\n';

    return 0;
}