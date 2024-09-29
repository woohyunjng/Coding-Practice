#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, x, y, z, st, en, md, res, bef;
    cin >> N >> x >> y >> z;

    st = 0, en = INF;
    while (st <= en) {
        md = st + en >> 1;
        if (md / x + md / y + md / z >= N) {
            res = md;
            en = md - 1;
        } else
            st = md + 1;
    }

    bef = (res - 1) / x + (res - 1) / y + (res - 1) / z;
    if (res % x == 0) {
        bef++;
        if (bef == N)
            cout << "A win";
    }
    if (res % y == 0) {
        bef++;
        if (bef == N)
            cout << "B win";
    }
    if (res % z == 0) {
        bef++;
        if (bef == N)
            cout << "C win";
    }

    return 0;
}