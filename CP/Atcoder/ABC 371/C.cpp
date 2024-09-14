#include <bits/stdc++.h>
#define int long long

#define MAX 10
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX][MAX];
bool conG[MAX][MAX], conH[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Mg, Mh, X, Y, res = INF, val;
    vector<int> perm;

    cin >> N;

    cin >> Mg;
    while (Mg--) {
        cin >> X >> Y;
        conG[X][Y] = true;
    }

    cin >> Mh;
    while (Mh--) {
        cin >> X >> Y;
        conH[X][Y] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1 + i; j <= N; j++)
            cin >> A[i][j];
        perm.push_back(i);
    }

    do {
        val = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                X = min(perm[i - 1], perm[j - 1]), Y = max(perm[i - 1], perm[j - 1]);
                if (conH[X][Y] ^ conG[i][j]) {
                    val += A[X][Y];
                }
            }
        }
        res = min(res, val);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << res;

    return 0;
}