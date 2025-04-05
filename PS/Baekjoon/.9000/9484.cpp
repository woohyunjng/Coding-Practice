#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 2001;

int X[MAX], Y[MAX], P[MAX];

double SZ(int A, int B, int C) { return (double)abs(X[A] * Y[B] + X[B] * Y[C] + X[C] * Y[A] - (X[A] * Y[C] + X[B] * Y[A] + X[C] * Y[B])) / 2; }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, A, B, C;
    double ans[2];

    vector<int> val;
    vector<pr> arr, rotating_line;

    while (true) {
        arr.clear(), rotating_line.clear(), val.clear();
        ans[0] = 20000 * 20000, ans[1] = 0;

        cin >> N;
        if (N == 0)
            break;

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
            for (int j = i + 1; j < N; j++)
                rotating_line.push_back({i, j});

        sort(rotating_line.begin(), rotating_line.end(), [&](pr x, pr y) {
            if ((Y[x[0]] - Y[x[1]]) * (X[y[0]] - X[y[1]]) == (Y[y[0]] - Y[y[1]]) * (X[x[0]] - X[x[1]]))
                return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
            return (Y[x[0]] - Y[x[1]]) * (X[y[0]] - X[y[1]]) < (Y[y[0]] - Y[y[1]]) * (X[x[0]] - X[x[1]]);
        });

        for (pr i : rotating_line) {
            A = i[0], B = i[1];

            if (min(P[A], P[B]) > 0)
                ans[0] = min(ans[0], SZ(A, B, val[min(P[A], P[B]) - 1]));
            if (max(P[A], P[B]) < N - 1)
                ans[0] = min(ans[0], SZ(A, B, val[max(P[A], P[B]) + 1]));

            ans[1] = max({ans[1], SZ(A, B, val[0]), SZ(A, B, val[N - 1])});
            swap(val[P[A]], val[P[B]]), swap(P[A], P[B]);
        }

        cout << fixed << setprecision(1);
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
}
