#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], Z[MAX][2], V[MAX], ans;

void gen_Z(int N, int T) {
    int L = 0, R = 0;

    Z[0][T] = N;
    for (int i = 1; i < N; i++) {
        Z[i][T] = 0;
        if (i <= R)
            Z[i][T] = min(R - i, Z[i - L][T]);
        while (i + Z[i][T] < N && V[Z[i][T]] == V[i + Z[i][T]])
            Z[i][T]++;
        if (i + Z[i][T] > R)
            L = i, R = i + Z[i][T];
    }
}

void dnc(int l, int r) {
    if (l >= r)
        return;

    int m = l + r >> 1;
    dnc(l, m), dnc(m + 1, r);

    int X, Y;

    for (int i = m + 1; i <= r; i++)
        V[i - m - 1] = A[i];
    for (int i = l; i <= m; i++)
        V[r - m + i - l] = A[i];
    gen_Z(r - l + 1, 0);

    for (int i = m; i >= l; i--)
        V[m - i] = A[i];
    gen_Z(m - l + 1, 1);

    for (int i = m; i > l; i--) {
        X = m - i + 1 - min({Z[r - m + i - l][0], r - m, m - i + 1}), Y = Z[m - i + 1][1];
        Y = min(Y, m - i), X = max(X, 1ll);
        ans += max(0ll, Y - X + 1);
    }

    for (int i = m; i >= l; i--)
        V[m - i] = A[i];
    for (int i = r; i > m; i--)
        V[m - l + 1 + r - i] = A[i];
    gen_Z(r - l + 1, 0);

    for (int i = m + 1; i <= r; i++)
        V[i - m - 1] = A[i];
    gen_Z(r - m, 1);

    for (int i = m + 1; i <= r; i++) {
        X = i - m - min({Z[m - l + 1 + r - i][0], i - m, m - l + 1}), Y = Z[i - m][1];
        Y = min(Y, i - m - 1), X = max(X, 1ll);
        if (i != r)
            ans += max(0ll, Y - X + 1);

        if (Z[m - l + 1 + r - i][0] >= i - m)
            ans++;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string _S;
    int N;

    while (true) {
        cin >> _S, N = _S.size();
        if (_S == "0")
            break;

        for (int i = 1; i <= N; i++) {
            if (_S[i - 1] == 'A')
                A[i] = 1;
            else if (_S[i - 1] == 'C')
                A[i] = 2;
            else if (_S[i - 1] == 'G')
                A[i] = 3;
            else
                A[i] = 4;
        }

        ans = 0, dnc(1, N);
        cout << ans << '\n';
    }

    return 0;
}