#include <bits/stdc++.h>
#define int long long

#define MAX 1000100

using namespace std;

int A[MAX], B[MAX], sm_A[MAX], sm_B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, res = 0;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1, greater<int>());
    for (int i = 1; i <= N; i++)
        sm_A[i] = sm_A[i - 1] + A[i];

    for (int i = 1; i <= M; i++)
        cin >> B[i];
    sort(B + 1, B + M + 1, greater<int>());
    for (int i = 1; i <= M; i++)
        sm_B[i] = sm_B[i - 1] + B[i];

    if (N * M == K) {
        cout << sm_A[N] + sm_B[M];
        return 0;
    }

    for (int i = 0; i < N && i * M <= K; i++) {
        res = max(
            res,
            sm_A[i] + sm_B[(K - M * i) / (N - i)]);
    }

    cout << res;

    return 0;
}