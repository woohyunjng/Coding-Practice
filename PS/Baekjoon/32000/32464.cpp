#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 1;
    cin >> N;

    for (int i = 1; i <= (N + 3) / 2; i++)
        res[i * 2 - 1] = 1 + (i - 1) * (i - 1);

    if (N & 1)
        res[2] = 3 * (N + 1) / 2 + 1;
    else
        res[2] = 3 * N / 2 + 2;

    for (int i = 2; i <= (N + 2) / 2; i++)
        res[i * 2] = res[i * 2 - 2] + 2 * (i - 1);

    for (int i = 1; i <= N + 2; i++)
        cout << res[i] << ' ';

    return 0;
}