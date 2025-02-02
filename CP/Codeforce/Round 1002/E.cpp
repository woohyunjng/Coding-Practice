#include <bits/stdc++.h>
#define int long long

#define MAX 800000
using namespace std;

int A[MAX], B[MAX], val[MAX];

void solve() {
    int N, M, X, K, ans, Y, Z;
    bool flag;
    vector<pr> arr;

    cin >> N >> M;

    for (int i = 1; i <= 2 * N * M; i++)
        val[i] = 0;

    for (int i = 1; i <= N * M; i++)
        cin >> A[i];
    for (int i = 1; i <= N * M; i++)
        cin >> B[i], val[B[i]] = i;

    ans = N * M;
    for (int i = 1; i <= N * M;) {
        flag = val[A[i]] != 0, X = val[A[i]], K = i;
        flag &= X > val[A[i - 1]];
        if (flag && (X - 1) / M == (i - 1) / M) {
            for (Y = i + 1, Z = X + 1; (Z - 1) % M != 0; Y++, Z++)
                flag &= val[A[Y]] == Z;
            if (flag)
                i = Y - 1;
        }

        if (!flag) {
            ans = i - 1;
            break;
        }
        i++;
    }

    for (int i = 1; i <= ans; i++) {
    }

    cout << N * M - ans << '\n';
    for (pr i : arr)
        cout << i.first << ' ' << i.second << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}