#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX][MAX], sm[MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, Lx, Ly, Lz, Rx, Ry, Rz, res;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++)
                cin >> arr[i][j][k];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                sm[i][j][k] = sm[i - 1][j][k] + sm[i][j - 1][k] + sm[i][j][k - 1] - sm[i - 1][j - 1][k] - sm[i - 1][j][k - 1] - sm[i][j - 1][k - 1] + sm[i - 1][j - 1][k - 1] + arr[i][j][k];
            }
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        res = sm[Rx][Ry][Rz] - sm[Lx - 1][Ry][Rz] - sm[Rx][Ly - 1][Rz] - sm[Rx][Ry][Lz - 1] + sm[Lx - 1][Ly - 1][Rz] + sm[Lx - 1][Ry][Lz - 1] + sm[Rx][Ly - 1][Lz - 1] - sm[Lx - 1][Ly - 1][Lz - 1];
        cout << res << '\n';
    }

    return 0;
}