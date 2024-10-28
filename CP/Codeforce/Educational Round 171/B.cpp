#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

void solve() {
    int N, res, st, en, md, X, Y;
    bool check;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    st = 1, en = INF;
    while (st <= en) {
        md = st + en >> 1;
        check = true;

        if (N & 1) {
            X = 0, Y = N + 1;
            for (int i = 1; i < N; i += 2) {
                if (A[i + 1] - A[i] > md)
                    break;
                X = i + 1;
            }

            for (int j = N - 1; j > 1; j -= 2) {
                if (A[j + 1] - A[j] > md)
                    break;
                Y = j;
            }

            if (Y - X > 2)
                check = false;
        } else {
            for (int i = 1; i < N; i += 2)
                check = check && (A[i + 1] - A[i] <= md);
        }

        if (check) {
            en = md - 1;
            res = md;
        } else
            st = md + 1;
    }

    cout << res << '\n';
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