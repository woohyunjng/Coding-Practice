#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX], two[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, res = 0;

    cin >> N;
    two[0] = 1;

    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        sm[X]++, sm[Y + 1]--;
        two[i] = two[i - 1] * 2 % MOD;
    }

    for (int i = 1; i <= 2 * N; i++) {
        sm[i] += sm[i - 1];
        res = (res + two[N - 1 - sm[i]]) % MOD;
    }

    cout << res << '\n';

    return 0;
}