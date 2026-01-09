#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

typedef array<int, 2> pr;

int D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, X, F, ans = 0;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        D[U]++, D[V]++;
    }

    for (int i = 0; i < N; i++)
        arr.push_back(i);
    sort(arr.begin(), arr.end(), [&](int x, int y) { return D[x] > D[y]; });

    F = -1, V = (M << 1) - ((N - 1) << 1), U = 0;
    for (int i = 0; i < N; i++) {
        if (D[arr[i]] >= N)
            F = i, V -= D[arr[i]] - (N - 1), D[arr[i]] = N - 1, ans++;
    }

    while (V > 0) {
        X = min(D[arr[U]] - 1, V);
        V -= X, D[arr[U]] -= X, ans += ((U++) > F);
    }
    sort(arr.begin(), arr.end(), [&](int x, int y) { return D[x] > D[y]; });

    cout << ans << '\n';
    cout << N << ' ' << N - 1 << '\n';

    V = 1;
    for (int i : arr)
        for (int j = 0; j < D[i]; j++)
            cout << i << ' ' << arr[V] << '\n', D[arr[V++]]--;

    return 0;
}