#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<double, 3> tp;

const int MAX = 1001;

int X[MAX], Y[MAX], uf[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V;
    double ans = 0;
    vector<tp> arr;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i], uf[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            arr.push_back({sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])), (double)i, (double)j});

    while (M--)
        cin >> U >> V, uni(U, V);

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        if (find((int)i[1]) != find((int)i[2]))
            ans += i[0], uni((int)i[1], (int)i[2]);
    }

    cout << fixed << setprecision(2);
    cout << ans << '\n';

    return 0;
}