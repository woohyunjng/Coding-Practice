#include <bits/stdc++.h>
#define int long long

#define MAX 6100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P, X, Y;
    cin >> N;

    while (N--) {
        cin >> X >> Y;
        sm[Y - X + 3000][X + Y + 3000]++;
    }

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            sm[i][j] += (i ? sm[i - 1][j] : 0) + (j ? sm[i][j - 1] : 0) - (i && j ? sm[i - 1][j - 1] : 0);

    cin >> P;
    while (P--) {
        cin >> X >> Y;
        cout << sm[Y - X + 3000][X + Y + 3000] << '\n';
    }

    return 0;
}