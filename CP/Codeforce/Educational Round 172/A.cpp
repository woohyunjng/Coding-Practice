#include <bits/stdc++.h>
#define int long long

#define MAX 51
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

void solve() {
    int N, K, res = 0, X = 0, Y = 1;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1, greater<int>());

    while (X + A[Y] <= K && Y <= N)
        X += A[Y++];
    cout << K - X << '\n';
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