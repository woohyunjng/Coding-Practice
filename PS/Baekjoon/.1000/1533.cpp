#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000003
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
                for (int k = 1; k <= N; k++)
                    res.arr[i][j] += arr[i][k] * A.arr[k][j];
                res.arr[i][j] %= MOD;
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

    SquareMatrix operator+(const SquareMatrix &A) const {
        SquareMatrix res(N);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                res.arr[i][j] = arr[i][j] + A.arr[i][j];
                res.arr[i][j] %= MOD;
            }
        }
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, E, T, X;
    string K;

    cin >> N >> S >> E >> T;

    SquareMatrix matrix(N * 5);

    for (int i = 1; i <= N; i++) {
        cin >> K;
        for (int j = 1; j <= N; j++) {
            X = K[j - 1] - '0';
            if (X >= 1)
                matrix.arr[(i - 1) * 5 + 1][(j - 1) * 5 + X] = 1;
        }
        for (int j = 1; j <= 4; j++)
            matrix.arr[(i - 1) * 5 + j + 1][(i - 1) * 5 + j] = 1;
    }

    matrix = matrix.pow(T);
    cout << matrix.arr[(S - 1) * 5 + 1][(E - 1) * 5 + 1] << endl;

    return 0;
}