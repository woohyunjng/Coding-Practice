#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MAX_LOG 20

#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int res[MAX];
bool checked[MAX];

void solve() {
    int N, X = 0, Y;
    cin >> N;

    fill(checked, checked + N + 1, false);

    Y = N;
    while (Y)
        Y >>= 1, X++;

    if (N & 1) {
        cout << N << '\n';

        res[N] = N, res[N - 1] = N - 1, res[N - 2] = 1;
        checked[N] = checked[N - 1] = checked[1] = true;

        X = 1;
        for (int i = 1; i <= N - 3; i++) {
            while (checked[X])
                X++;
            res[i] = X++;
        }
    } else {
        cout << (1 << X) - 1 << '\n';
        if ((1 << (X - 1)) == N) {
            res[N] = N, res[N - 1] = N - 1, res[N - 2] = N - 2, res[N - 3] = 1;
            checked[N] = checked[N - 1] = checked[N - 2] = checked[1] = true;

            X = 1;
            for (int i = 1; i <= N - 4; i++) {
                while (checked[X])
                    X++;
                res[i] = X++;
            }
        } else {
            res[N] = N, res[N - 1] = ((1 << X) - 1) ^ N;
            for (int i = 0; i < X - 1; i++) {
                if ((res[N - 1] & (1 << i)) == 0) {
                    res[N - 2] = res[N - 1] | (1 << i);
                    break;
                }
            }

            checked[res[N]] = checked[res[N - 1]] = checked[res[N - 2]] = true;

            X = 1;
            for (int i = 1; i <= N - 3; i++) {
                while (checked[X])
                    X++;
                res[i] = X++;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';
    cout << '\n';
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