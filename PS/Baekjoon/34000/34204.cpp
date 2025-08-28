#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;

int A[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, C, V = 0;

    cin >> N >> K >> C;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; i++)
        S[i] = S[i - 1] + A[i];

    for (int i = 1; i <= C; i++) {
        while (V + 1 <= N - K && S[V + 1] <= i)
            V++;
        cout << S[V + K] - S[V] << '\n';
    }

    return 0;
}