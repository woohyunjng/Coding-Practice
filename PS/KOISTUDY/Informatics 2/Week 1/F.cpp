#include <bits/stdc++.h>
#define int long long

#define MAX 1010
#define MAX_MATRIX 15
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Matrix {
    int arr[MAX_MATRIX][MAX_MATRIX] = {}, W, H;
    bool possible = true;

    Matrix operator+(Matrix &A) {
        Matrix res;
        if (H != A.H || W != A.W) {
            res.possible = false;
            return res;
        }

        res.possible = true;
        res.H = H, res.W = W;

        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= W; j++)
                res.arr[i][j] = arr[i][j] + A.arr[i][j];
        return res;
    }

    Matrix operator-(Matrix &A) {
        Matrix res;
        if (H != A.H || W != A.W) {
            res.possible = false;
            return res;
        }

        res.possible = true;
        res.H = H, res.W = W;

        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= W; j++)
                res.arr[i][j] = arr[i][j] - A.arr[i][j];
        return res;
    }

    Matrix operator*(Matrix &A) {
        Matrix res;
        if (W != A.H) {
            res.possible = false;
            return res;
        }

        res.H = H, res.W = A.W;
        res.possible = true;

        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= A.W; j++)
                for (int k = 1; k <= W; k++)
                    res.arr[i][j] += arr[i][k] * A.arr[k][j];
        return res;
    }

    void print() {
        if (!possible)
            cout << "impossible!" << endl;
        else {
            for (int i = 1; i <= H; i++) {
                for (int j = 1; j <= W; j++)
                    cout << arr[i][j] << ' ';
                cout << endl;
            }
        }
    }
};

Matrix arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B;
    char T;

    Matrix res;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].H >> arr[i].W;
        arr[i].possible = true;
        for (int j = 1; j <= arr[i].H; j++)
            for (int k = 1; k <= arr[i].W; k++)
                cin >> arr[i].arr[j][k];
    }

    cin >> Q;
    while (Q--) {
        cin >> A >> T >> B;
        if (T == '+')
            res = arr[A] + arr[B];
        else if (T == '-')
            res = arr[A] - arr[B];
        else
            res = arr[A] * arr[B];
        res.print();
    }

    return 0;
}