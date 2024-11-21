#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void compress(int X);

vector<int> child[MAX];

int parent[MAX], res[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }

void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);

    parent[Y] = X;
    if (child[X].size() < child[Y].size())
        swap(child[X], child[Y]);

    for (int i : child[Y])
        child[X].push_back(i);
    child[Y].clear();
    compress(X);
}

void compress(int X) {
    X = find(X);
    if (child[X].size() <= 1)
        return;
    for (int i = 1; i < child[X].size(); i++)
        uni(child[X][0], child[X][i]);
    if (child[X].empty())
        return;
    int K = find(child[X][0]);
    child[X].clear();
    child[X].push_back(K);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, cnt = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    while (M--) {
        cin >> X >> Y;
        child[X].push_back(Y);
    }

    for (int i = 1; i <= N; i++)
        compress(i);

    for (int i = 1; i <= N; i++) {
        if (find(i) == i)
            res[i] = ++cnt;
    }

    for (int i = 1; i <= N; i++)
        cout << res[find(i)] << '\n';

    return 0;
}