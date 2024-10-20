#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

void solve() {
    int N, K, res = 0, X, Y, st, en, md;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    st = 1, en = *max_element(A + 1, A + N + 1);

    while (st <= en) {
        md = st + en >> 1;
        X = 0, Y = 0;

        for (int i = 1; i <= N; i++) {
            if (A[i] < md)
                X++;
            Y += min(A[i], md);
        }

        if (Y >= K)
            res = X, en = md - 1;
        else
            st = md + 1;
    }

    cout << res + K << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}