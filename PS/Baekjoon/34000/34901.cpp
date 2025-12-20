#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 2001;

int X[MAX], Y[MAX], C[MAX], uf[MAX];

int find(int K) { return K == uf[K] ? K : uf[K] = find(uf[K]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, U, V;
    vector<tp> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> C[i], uf[i] = i, ans -= C[i];
        for (int j = 0; j < i; j++)
            arr.push_back({abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + C[i] + C[j], i, j});
    }

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        U = find(i[1]), V = find(i[2]);
        if (U == V)
            continue;
        uf[U] = V, ans += i[0];
    }

    for (int i = 0; i < N; i++)
        cout << ans + C[i] << ' ';
    cout << '\n';

    return 0;
}