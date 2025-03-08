#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int B[MAX], W[MAX], smB[MAX], smW[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    sort(B + 1, B + N + 1, greater<int>());

    for (int i = 1; i <= M; i++)
        cin >> W[i];
    sort(W + 1, W + M + 1, greater<int>());

    for (int i = 1; i <= N; i++)
        smB[i] = smB[i - 1] + B[i];
    for (int i = 1; i <= M; i++) {
        smW[i] = smW[i - 1] + W[i];
        smW[i] = max(smW[i], smW[i - 1]);
    }

    for (int i = 1; i <= N; i++)
        ans = max(ans, smB[i] + smW[min(M, i)]);

    cout << ans << '\n';

    return 0;
}