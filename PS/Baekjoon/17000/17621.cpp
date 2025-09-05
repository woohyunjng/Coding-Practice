#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100002;

int A[MAX], B[MAX], V[MAX][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        A[i] = N + 1 - A[i], B[i] = N + 1 - B[i];
        swap(A[i], B[i]);

        if (A[i] == N + 1)
            A[i] = B[i] = 0;
    }

    for (int i = 1; i <= M; i++)
        V[i][0] = max(V[i - 1][0], A[i] == 1 ? B[i] : 0);
    for (int i = M; i >= 1; i--)
        V[i][1] = max(V[i + 1][1], A[i] == 1 ? B[i] : 0);

    for (int i = 1; i <= M; i++)
        ans += min(V[i][0], V[i][1]) - (A[i] == 1 ? B[i] : 0);

    for (int i = 1; i <= M; i++) {
        if (A[i] <= 1)
            continue;

        X = i;
        while (X + 1 <= M && !(A[X + 1] > B[X] || B[X + 1] < A[X]))
            X++;

        V[i - 1][2] = V[X + 1][3] = 0;
        for (int j = i; j <= X; j++)
            V[j][2] = max(V[j - 1][2], A[i] != 1 ? B[j] : 0);
        for (int j = X; j >= i; j--)
            V[j][3] = max(V[j + 1][3], A[i] != 1 ? B[j] : 0);

        for (int j = i; j <= X; j++) {
            ans += min(V[j][2], V[j][3]) - B[j];
            if (A[j] <= min(V[j][0], V[j][1]))
                ans -= min({V[j][0], V[j][1], V[j][2], V[j][3]}) - A[j] + 1;
        }
        i = X;
    }

    cout << ans << '\n';

    return 0;
}