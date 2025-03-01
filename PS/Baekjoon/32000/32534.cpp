#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 400000;

int par[MAX];
map<pr, bool> dir;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Q, cnt = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y, par[Y]++;
        if (X > Y)
            dir[{Y, X}] = true;
        else
            dir[{X, Y}] = false;
    }

    for (int i = 1; i <= N; i++)
        cnt += par[i] == 0;
    cout << (cnt == 1 ? "DA" : "NE") << '\n';

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        if (X > Y)
            swap(X, Y);
        cnt -= par[X] == 0, cnt -= par[Y] == 0;
        if (dir[{X, Y}])
            par[X]--, par[Y]++;
        else
            par[X]++, par[Y]--;
        cnt += par[X] == 0, cnt += par[Y] == 0;
        dir[{X, Y}] = !dir[{X, Y}];
        cout << (cnt == 1 ? "DA" : "NE") << '\n';
    }

    return 0;
}