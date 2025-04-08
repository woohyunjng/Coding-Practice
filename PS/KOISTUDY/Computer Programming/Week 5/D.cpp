#include <bits/stdc++.h>
using namespace std;

vector<int> arr[21];
int V[21];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, A, K;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> X, A = 1 << 20, K = 0;
        for (int j = 1; j <= N; j++) {
            if (V[j] < A)
                A = V[j], K = j;
        }
        V[K] += X, arr[K].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i])
            cout << j << ' ';
        cout << '\n';
    }
}