#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1001;

int _query[MAX][MAX], ans[MAX];

int query(int X, int Y) {
    if (X >= Y)
        return 0;
    if (_query[X][Y] != -1)
        return _query[X][Y];

    int res;

    cout << "? " << X << ' ' << Y << '\n', cout.flush();
    cin >> res;

    return _query[X][Y] = res;
}

int comp(int X, int Y) { return (((query(X, Y) - query(X, Y - 1) + 2) % 2) - ((query(X + 1, Y) - query(X + 1, Y - 1) + 2) % 2) + 2) % 2 == 1; }

vector<int> merge(int l, int r) {
    vector<int> res, lft, rgt;
    if (l == r)
        return {l};

    int m = l + r >> 1, X = 0, Y = 0;
    lft = merge(l, m), rgt = merge(m + 1, r);

    while (X < lft.size() && Y < rgt.size()) {
        if (comp(lft[X], rgt[Y]) == 1)
            res.push_back(rgt[Y++]);
        else
            res.push_back(lft[X++]);
    }

    while (X < lft.size())
        res.push_back(lft[X++]);
    while (Y < rgt.size())
        res.push_back(rgt[Y++]);

    return res;
}

signed main() {
    int N = 1000;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            _query[i][j] = -1;

    vector<int> res = merge(1, N);

    for (int i = 0; i < N; i++)
        ans[res[i]] = i + 1;

    cout << '!' << '\n';
    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n', cout.flush();

    return 0;
}