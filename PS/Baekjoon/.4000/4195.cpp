#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int uf[MAX], sz[MAX];
map<string, int> mp;

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    uf[Y] = X, sz[X] += sz[Y];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M;
    string A, B;

    cin >> T;
    while (T--) {
        cin >> M, N = 0, mp.clear();

        while (M--) {
            cin >> A >> B;
            if (!mp.count(A))
                mp[A] = ++N, sz[N] = 1, uf[N] = N;
            if (!mp.count(B))
                mp[B] = ++N, sz[N] = 1, uf[N] = N;
            uni(mp[A], mp[B]);
            cout << sz[find(mp[A])] << '\n';
        }
    }

    return 0;
}