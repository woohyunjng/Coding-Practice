#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int parent[MAX], sz[MAX];

int find(int X) {
    if (parent[X] != X)
        parent[X] = find(parent[X]);
    return parent[X];
}

pr connection[MAX];
int queries[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, res = 0, X, Y;

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
        parent[i] = i, sz[i] = 1;

    for (int i = 1; i <= M; i++)
        cin >> connection[i].first >> connection[i].second;

    for (int i = 1; i <= Q; i++) {
        cin >> queries[i];
        checked[queries[i]] = true;
    }

    for (int i = 1; i <= M; i++) {
        if (checked[i])
            continue;

        X = find(connection[i].first), Y = find(connection[i].second);
        if (X == Y)
            continue;
        if (X > Y)
            swap(X, Y);

        parent[Y] = X;
        sz[X] += sz[Y];
    }

    for (int i = Q; i >= 1; i--) {
        X = find(connection[queries[i]].first), Y = find(connection[queries[i]].second);
        if (X == Y)
            continue;

        if (X > Y)
            swap(X, Y);

        parent[Y] = X;
        res += sz[X] * sz[Y];
        sz[X] += sz[Y];
    }

    cout << res;

    return 0;
}