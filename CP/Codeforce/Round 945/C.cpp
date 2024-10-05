#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], res[2][MAX];

void solve() {
    int N, X = 0, Y = 0, K = 0;
    vector<pr> even, odd;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        if (i & 1)
            odd.push_back({P[i], i});
        else
            even.push_back({P[i], i});
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    for (int i = 0; i < N / 2; i++) {
        res[0][odd[i].second] = N - i;
        res[0][even[i].second] = N / 2 - i;

        res[1][odd[i].second] = N / 2 - i;
        res[1][even[i].second] = N - i;
    }

    for (int i = 3; i < N; i += 2) {
        if (P[i] + res[0][i] > P[i - 1] + res[0][i - 1] && P[i] + res[0][i] > P[i + 1] + res[0][i + 1])
            X++;
    }
    for (int i = 2; i < N; i += 2) {
        if (P[i] + res[1][i] > P[i - 1] + res[1][i - 1] && P[i] + res[1][i] > P[i + 1] + res[1][i + 1])
            Y++;
    }

    if (Y > X)
        K = 1;

    for (int i = 1; i <= N; i++)
        cout << res[K][i] << ' ';
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