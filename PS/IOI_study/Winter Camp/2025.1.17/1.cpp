#include <bits/stdc++.h>
#define int long long
#define double long double

#define MAX 100100
using namespace std;
typedef array<int, 2> pr;

int X[MAX], Y[MAX];

double triangle(pr A, pr B, pr C) {
    return abs(A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - A[1] * B[0] - B[1] * C[0] - C[1] * A[0]) / 2.0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    double res = 0;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    for (int i = 2; i < N; i++)
        res += triangle({X[1], Y[1]}, {X[i], Y[i]}, {X[i + 1], Y[i + 1]});
    cout << fixed << setprecision(1) << res << '\n';

    return 0;
}