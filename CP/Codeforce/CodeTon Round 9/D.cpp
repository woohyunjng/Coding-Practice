#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int S[MAX], res[MAX];

void solve() {
    int N, M;
    bool flag = true;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
        cin >> S[i];
    sort(S + 1, S + M + 1, greater<int>());
    fill(res, res + N + 1, 0);

    for (int i = 1; i <= N; i++) {
        res[i]++;
        if (res[i] > M)
            flag = false;

        for (int j = i * 2; j <= N; j += i)
            res[j] = res[i];
    }

    if (!flag) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
        cout << S[res[i]] << ' ';
    cout << '\n';
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