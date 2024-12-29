#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[3][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z, val[3] = {0};
    cin >> N >> Q;

    while (Q--) {
        cin >> X >> Y >> Z;
        if (++sm[0][X][Y] == N)
            val[0]++;
        if (++sm[1][Y][Z] == N)
            val[1]++;
        if (++sm[2][Z][X] == N)
            val[2]++;
        cout << val[0] + val[1] + val[2] << '\n';
    }

    return 0;
}