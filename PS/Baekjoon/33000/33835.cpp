#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int X[MAX], Y[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    cout << fixed << setprecision(4) << sqrt((X[1] - X[N]) * (X[1] - X[N]) + (Y[1] - Y[N]) * (Y[1] - Y[N])) << '\n';

    return 0;
}