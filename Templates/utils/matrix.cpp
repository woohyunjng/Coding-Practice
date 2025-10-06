const int SZ = 5;

typedef array<array<int, SZ>, SZ> matrix;

matrix mul(matrix A, matrix B) {
    matrix res = {};
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            for (int k = 0; k < SZ; k++)
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
    return res;
}

matrix sum(matrix A, matrix B) {
    matrix res = {};
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            res[i][j] = (A[i][j] + B[i][j]) % MOD;
    return res;
}