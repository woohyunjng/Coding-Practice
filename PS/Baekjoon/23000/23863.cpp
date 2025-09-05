#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

typedef array<int, 2> pr;

const int MAX = 10000001;

int X[MAX], Y[MAX], P[MAX], R[MAX];

double dis(int A, int B) { return sqrt((X[A] - X[B]) * (X[A] - X[B]) + (Y[A] - Y[B]) * (Y[A] - Y[B])); }
double dis(int A, int B, int C) { return (double)abs((Y[B] - Y[A]) * X[C] - (X[B] - X[A]) * Y[C] + X[B] * Y[A] - Y[B] * X[A]) / dis(A, B); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C = 0;
    double ans = 0;

    vector<pr> arr, rotating_line;
    vector<int> val;

    cin >> N, C = N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        arr.push_back({X[i], Y[i]});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        X[i] = arr[i][0], Y[i] = arr[i][1];
        val.push_back(i), P[i] = i;
    }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            rotating_line.push_back({i, j});
            (X[j] - X[i]), (Y[j] - Y[i]);
            if (Y[i] <= Y[j])
                X[C] = X[i] + Y[j] - Y[i], Y[C] = Y[i] - (X[j] - X[i]);
            else
                X[C] = X[i] - (Y[j] - Y[i]), Y[C] = Y[i] + (X[j] - X[i]);
            R[C] = j, rotating_line.push_back({i, C++});
        }

    sort(rotating_line.begin(), rotating_line.end(), [&](pr x, pr y) {
        int TX = x[1] < N, TY = y[1] < N;
        if ((Y[x[0]] - Y[x[1]]) * (X[y[0]] - X[y[1]]) == (Y[y[0]] - Y[y[1]]) * (X[x[0]] - X[x[1]])) {
            return tie(TX, x[0], TX ? x[1] : R[x[1]]) < tie(TY, y[0], TY ? y[1] : R[y[1]]);
        }
        return (Y[x[0]] - Y[x[1]]) * (X[y[0]] - X[y[1]]) < (Y[y[0]] - Y[y[1]]) * (X[x[0]] - X[x[1]]);
    });

    for (pr i : rotating_line) {
        A = i[0], B = i[1];
        if (B >= N) {
            B = R[B];
            if (P[A] > P[B])
                swap(A, B);
            if (P[A] + 1 == P[B])
                ans = max(ans, dis(A, B));
        } else {
            swap(val[P[A]], val[P[B]]), swap(P[A], P[B]);
            if (P[A] > P[B])
                swap(A, B);

            if (P[A] > 0)
                ans = max(ans, dis(A, B, val[P[A] - 1]));
            if (P[B] < N - 1)
                ans = max(ans, dis(A, B, val[P[B] + 1]));
        }
    }

    cout << fixed << setprecision(9);
    cout << (double)ans / 2 << '\n';

    return 0;
}