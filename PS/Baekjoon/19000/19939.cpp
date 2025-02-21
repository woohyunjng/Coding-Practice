#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, val = 0;
    cin >> N >> K;

    for (int i = 1; i <= K; i++)
        A[i] = i, val += i;

    if (val > N) {
        cout << -1 << '\n';
        return 0;
    }
    val = N - val;

    for (int i = K; i >= 1; i--) {
        A[i] += val / K;
        if (val % K >= K - i + 1)
            A[i]++;
    }

    cout << A[K] - A[1] << '\n';

    return 0;
}