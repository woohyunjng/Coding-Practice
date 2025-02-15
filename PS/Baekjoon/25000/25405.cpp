#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;

int L[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, V, S;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> L[i];
    sort(L + 1, L + N + 1);

    cin >> M >> K;
    X = Y = K, S = L[K] + M;

    while (true) {
        V = S / (Y - X + 1);
        if (1 < X && V <= L[X - 1] + M)
            S += L[--X] + M;
        else if (Y < N && V >= L[Y + 1])
            S += L[++Y];
        else
            break;
    }

    for (int i = 1; i <= N; i++) {
        if (i < X)
            ans[i] = L[i] + M;
        else if (i <= Y - S % (Y - X + 1))
            ans[i] = S / (Y - X + 1);
        else if (i <= Y)
            ans[i] = S / (Y - X + 1) + 1;
        else
            ans[i] = L[i];
    }

    sort(ans + 1, ans + N + 1);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}