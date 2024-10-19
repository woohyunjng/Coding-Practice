#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = 0;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> D[i];
    sort(D + 1, D + N + 1, greater<int>());

    for (int i = 1; i <= N; i++)
        res += (i + K - 1) / K * D[i];

    cout << res;

    return 0;
}