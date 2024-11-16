#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 998244353
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int two[MAX], L[MAX], R[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X = 0, Y = 0, res = 0;
    vector<pr> arr;

    cin >> N >> M;

    two[0] = 1;
    for (int i = 1; i <= N; i++)
        two[i] = (two[i - 1] * 2) % MOD;

    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i];

    for (int i = 1; i <= M; i++) {
        cin >> S[i];
        arr.push_back({S[i], 0});
    }
    sort(S + 1, S + M + 1);

    for (int i = 1; i <= N; i++) {
        if (lower_bound(S + 1, S + M + 1, L[i]) - S == upper_bound(S + 1, S + M + 1, R[i]) - S)
            continue;
        arr.push_back({L[i], -1});
        arr.push_back({R[i], 1});
    }

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        if (i.second == 0) {
            res = (res + (two[Y] - 1) * two[X - Y]) % MOD;
            Y = 0;
        } else
            X -= i.second, Y += i.second == -1;
    }

    cout << res << '\n';

    return 0;
}