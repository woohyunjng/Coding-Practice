#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SquareMatrix {
  public:
    int N;
    vector<vector<int>> arr;

    SquareMatrix(int N) : N(N) {
        arr.resize(N + 1, vector<int>(N + 1, 0));
    }

    SquareMatrix operator*(const SquareMatrix &A) const {
        SquareMatrix res(N);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    res.arr[i][j] += arr[i][k] * A.arr[k][j];
                    res.arr[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    SquareMatrix pow(long long B) {
        SquareMatrix res(N), tmp = *this;

        for (int i = 1; i <= N; i++)
            res.arr[i][i] = 1;

        while (B) {
            if (B & 1)
                res = res * tmp;
            tmp = tmp * tmp;
            B >>= 1;
        }

        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, D, X, A, B, C;
    cin >> T >> N >> D;

    SquareMatrix res(N);
    vector<SquareMatrix> arr(T + 1, SquareMatrix(N));

    for (int i = 1; i <= N; i++)
        res.arr[i][i] = 1;

    for (int i = 1; i <= T; i++) {
        cin >> X;
        while (X--) {
            cin >> A >> B >> C;
            arr[i].arr[A][B] = C;
        }

        res = res * arr[i];
    }

    res = res.pow(D / T);

    for (int i = 1; i <= D % T; i++)
        res = res * arr[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << res.arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}