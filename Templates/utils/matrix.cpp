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
                }
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